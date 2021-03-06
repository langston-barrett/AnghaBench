#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
struct TYPE_5__ {scalar_t__ (* read_posted ) (struct ixgbe_hw*,int*,int,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* write_posted ) (struct ixgbe_hw*,int*,int,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* check_for_rst ) (struct ixgbe_hw*,int /*<<< orphan*/ ) ;} ;
struct ixgbe_mbx_info {TYPE_2__ ops; int /*<<< orphan*/  timeout; } ;
struct TYPE_4__ {int /*<<< orphan*/  (* stop_adapter ) (struct ixgbe_hw*) ;} ;
struct TYPE_6__ {int mc_filter_type; int /*<<< orphan*/  perm_addr; TYPE_1__ ops; } ;
struct ixgbe_hw {TYPE_3__ mac; int /*<<< orphan*/  api_version; struct ixgbe_mbx_info mbx; } ;
typedef  scalar_t__ s32 ;

/* Variables and functions */
 int /*<<< orphan*/  DEBUGFUNC (char*) ; 
 int /*<<< orphan*/  DEBUGOUT (char*) ; 
 int /*<<< orphan*/  IXGBE_CTRL_RST ; 
 scalar_t__ IXGBE_ERR_INVALID_MAC_ADDR ; 
 scalar_t__ IXGBE_ERR_RESET_FAILED ; 
 int /*<<< orphan*/  IXGBE_ETH_LENGTH_OF_ADDRESS ; 
 int /*<<< orphan*/  IXGBE_VFCTRL ; 
 int /*<<< orphan*/  IXGBE_VFWRITE_REG (struct ixgbe_hw*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int IXGBE_VF_INIT_TIMEOUT ; 
 int /*<<< orphan*/  IXGBE_VF_MBX_INIT_TIMEOUT ; 
 size_t IXGBE_VF_MC_TYPE_WORD ; 
 int IXGBE_VF_PERMADDR_MSG_LEN ; 
 int IXGBE_VF_RESET ; 
 int IXGBE_VT_MSGTYPE_ACK ; 
 int IXGBE_VT_MSGTYPE_NACK ; 
 int /*<<< orphan*/  IXGBE_WRITE_FLUSH (struct ixgbe_hw*) ; 
 int /*<<< orphan*/  ixgbe_mbox_api_10 ; 
 int /*<<< orphan*/  ixgbe_virt_clr_reg (struct ixgbe_hw*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msec_delay (int) ; 
 int /*<<< orphan*/  stub1 (struct ixgbe_hw*) ; 
 int /*<<< orphan*/  stub2 (struct ixgbe_hw*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (struct ixgbe_hw*,int*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ stub4 (struct ixgbe_hw*,int*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usec_delay (int) ; 

s32 ixgbe_reset_hw_vf(struct ixgbe_hw *hw)
{
	struct ixgbe_mbx_info *mbx = &hw->mbx;
	u32 timeout = IXGBE_VF_INIT_TIMEOUT;
	s32 ret_val = IXGBE_ERR_INVALID_MAC_ADDR;
	u32 msgbuf[IXGBE_VF_PERMADDR_MSG_LEN];
	u8 *addr = (u8 *)(&msgbuf[1]);

	DEBUGFUNC("ixgbevf_reset_hw_vf");

	/* Call adapter stop to disable tx/rx and clear interrupts */
	hw->mac.ops.stop_adapter(hw);

	/* reset the api version */
	hw->api_version = ixgbe_mbox_api_10;

	DEBUGOUT("Issuing a function level reset to MAC\n");

	IXGBE_VFWRITE_REG(hw, IXGBE_VFCTRL, IXGBE_CTRL_RST);
	IXGBE_WRITE_FLUSH(hw);

	msec_delay(50);

	/* we cannot reset while the RSTI / RSTD bits are asserted */
	while (!mbx->ops.check_for_rst(hw, 0) && timeout) {
		timeout--;
		usec_delay(5);
	}

	if (!timeout)
		return IXGBE_ERR_RESET_FAILED;

	/* Reset VF registers to initial values */
	ixgbe_virt_clr_reg(hw);

	/* mailbox timeout can now become active */
	mbx->timeout = IXGBE_VF_MBX_INIT_TIMEOUT;

	msgbuf[0] = IXGBE_VF_RESET;
	mbx->ops.write_posted(hw, msgbuf, 1, 0);

	msec_delay(10);

	/*
	 * set our "perm_addr" based on info provided by PF
	 * also set up the mc_filter_type which is piggy backed
	 * on the mac address in word 3
	 */
	ret_val = mbx->ops.read_posted(hw, msgbuf,
			IXGBE_VF_PERMADDR_MSG_LEN, 0);
	if (ret_val)
		return ret_val;

	if (msgbuf[0] != (IXGBE_VF_RESET | IXGBE_VT_MSGTYPE_ACK) &&
	    msgbuf[0] != (IXGBE_VF_RESET | IXGBE_VT_MSGTYPE_NACK))
		return IXGBE_ERR_INVALID_MAC_ADDR;

	if (msgbuf[0] == (IXGBE_VF_RESET | IXGBE_VT_MSGTYPE_ACK))
		memcpy(hw->mac.perm_addr, addr, IXGBE_ETH_LENGTH_OF_ADDRESS);

	hw->mac.mc_filter_type = msgbuf[IXGBE_VF_MC_TYPE_WORD];

	return ret_val;
}