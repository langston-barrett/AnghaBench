#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct qlcnic_adapter {TYPE_1__* pdev; int /*<<< orphan*/  ahw; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int EBUSY ; 
 int /*<<< orphan*/  QLCWRX (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  QLC_83XX_IDC_DEV_FAILED ; 
 int /*<<< orphan*/  QLC_83XX_IDC_DEV_STATE ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  qlcnic_83xx_idc_clear_registers (struct qlcnic_adapter*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  qlcnic_83xx_idc_log_state_history (struct qlcnic_adapter*) ; 
 scalar_t__ qlcnic_83xx_lock_driver (struct qlcnic_adapter*) ; 
 int /*<<< orphan*/  qlcnic_83xx_unlock_driver (struct qlcnic_adapter*) ; 

__attribute__((used)) static int qlcnic_83xx_idc_enter_failed_state(struct qlcnic_adapter *adapter,
					      int lock)
{
	if (lock) {
		if (qlcnic_83xx_lock_driver(adapter))
			return -EBUSY;
	}

	qlcnic_83xx_idc_clear_registers(adapter, 0);
	QLCWRX(adapter->ahw, QLC_83XX_IDC_DEV_STATE, QLC_83XX_IDC_DEV_FAILED);
	if (lock)
		qlcnic_83xx_unlock_driver(adapter);

	qlcnic_83xx_idc_log_state_history(adapter);
	dev_info(&adapter->pdev->dev, "Device will enter failed state\n");

	return 0;
}