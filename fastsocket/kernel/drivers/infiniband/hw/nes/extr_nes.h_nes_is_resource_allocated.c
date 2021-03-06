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
struct nes_adapter {int /*<<< orphan*/  resource_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  NES_DBG_HW ; 
 int /*<<< orphan*/  nes_debug (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int test_bit (int /*<<< orphan*/ ,unsigned long*) ; 

__attribute__((used)) static inline int nes_is_resource_allocated(struct nes_adapter *nesadapter,
		unsigned long *resource_array, u32 resource_num)
{
	unsigned long flags;
	int bit_is_set;

	spin_lock_irqsave(&nesadapter->resource_lock, flags);

	bit_is_set = test_bit(resource_num, resource_array);
	nes_debug(NES_DBG_HW, "resource_num %u is%s allocated.\n",
			resource_num, (bit_is_set ? "": " not"));
	spin_unlock_irqrestore(&nesadapter->resource_lock, flags);

	return bit_is_set;
}