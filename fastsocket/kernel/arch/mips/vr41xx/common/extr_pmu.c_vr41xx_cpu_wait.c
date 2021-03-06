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

/* Variables and functions */
 int /*<<< orphan*/  local_irq_disable () ; 
 int /*<<< orphan*/  local_irq_enable () ; 
 int /*<<< orphan*/  need_resched () ; 

__attribute__((used)) static void vr41xx_cpu_wait(void)
{
	local_irq_disable();
	if (!need_resched())
		/*
		 * "standby" sets IE bit of the CP0_STATUS to 1.
		 */
		__asm__("standby;\n");
	else
		local_irq_enable();
}