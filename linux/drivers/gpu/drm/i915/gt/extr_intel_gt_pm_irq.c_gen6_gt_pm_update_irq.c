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
typedef  int u32 ;
struct intel_gt {int pm_imr; int /*<<< orphan*/  irq_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  lockdep_assert_held (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  write_pm_imr (struct intel_gt*) ; 

__attribute__((used)) static void gen6_gt_pm_update_irq(struct intel_gt *gt,
				  u32 interrupt_mask,
				  u32 enabled_irq_mask)
{
	u32 new_val;

	WARN_ON(enabled_irq_mask & ~interrupt_mask);

	lockdep_assert_held(&gt->irq_lock);

	new_val = gt->pm_imr;
	new_val &= ~interrupt_mask;
	new_val |= ~enabled_irq_mask & interrupt_mask;

	if (new_val != gt->pm_imr) {
		gt->pm_imr = new_val;
		write_pm_imr(gt);
	}
}