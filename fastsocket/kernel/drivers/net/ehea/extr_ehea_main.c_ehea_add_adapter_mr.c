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
struct ehea_adapter {int /*<<< orphan*/  mr; scalar_t__ active_ports; } ;

/* Variables and functions */
 int ehea_reg_kernel_mr (struct ehea_adapter*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int ehea_add_adapter_mr(struct ehea_adapter *adapter)
{
	if (adapter->active_ports)
		return 0;

	return ehea_reg_kernel_mr(adapter, &adapter->mr);
}