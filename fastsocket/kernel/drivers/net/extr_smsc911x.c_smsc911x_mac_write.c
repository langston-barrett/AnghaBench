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
typedef  unsigned int u32 ;
struct smsc911x_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BYTE_TEST ; 
 int /*<<< orphan*/  HW ; 
 int /*<<< orphan*/  MAC_CSR_CMD ; 
 unsigned int MAC_CSR_CMD_CSR_BUSY_ ; 
 int /*<<< orphan*/  MAC_CSR_DATA ; 
 int /*<<< orphan*/  SMSC_ASSERT_MAC_LOCK (struct smsc911x_data*) ; 
 int /*<<< orphan*/  SMSC_WARNING (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ likely (int) ; 
 scalar_t__ smsc911x_mac_complete (struct smsc911x_data*) ; 
 unsigned int smsc911x_reg_read (struct smsc911x_data*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  smsc911x_reg_write (struct smsc911x_data*,int /*<<< orphan*/ ,unsigned int) ; 
 scalar_t__ unlikely (unsigned int) ; 

__attribute__((used)) static void smsc911x_mac_write(struct smsc911x_data *pdata,
			       unsigned int offset, u32 val)
{
	unsigned int temp;

	SMSC_ASSERT_MAC_LOCK(pdata);

	temp = smsc911x_reg_read(pdata, MAC_CSR_CMD);
	if (unlikely(temp & MAC_CSR_CMD_CSR_BUSY_)) {
		SMSC_WARNING(HW,
			"smsc911x_mac_write failed, MAC busy at entry");
		return;
	}

	/* Send data to write */
	smsc911x_reg_write(pdata, MAC_CSR_DATA, val);

	/* Write the actual data */
	smsc911x_reg_write(pdata, MAC_CSR_CMD, ((offset & 0xFF) |
		MAC_CSR_CMD_CSR_BUSY_));

	/* Workaround for hardware read-after-write restriction */
	temp = smsc911x_reg_read(pdata, BYTE_TEST);

	/* Wait for the write to complete */
	if (likely(smsc911x_mac_complete(pdata) == 0))
		return;

	SMSC_WARNING(HW,
		"smsc911x_mac_write failed, MAC busy after write");
}