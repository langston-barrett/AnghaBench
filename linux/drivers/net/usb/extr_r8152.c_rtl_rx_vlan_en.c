#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct r8152 {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CPCR_RX_VLAN ; 
 int /*<<< orphan*/  MCU_TYPE_PLA ; 
 int /*<<< orphan*/  PLA_CPCR ; 
 int /*<<< orphan*/  ocp_read_word (struct r8152*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ocp_write_word (struct r8152*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void rtl_rx_vlan_en(struct r8152 *tp, bool enable)
{
	u32 ocp_data;

	ocp_data = ocp_read_word(tp, MCU_TYPE_PLA, PLA_CPCR);
	if (enable)
		ocp_data |= CPCR_RX_VLAN;
	else
		ocp_data &= ~CPCR_RX_VLAN;
	ocp_write_word(tp, MCU_TYPE_PLA, PLA_CPCR, ocp_data);
}