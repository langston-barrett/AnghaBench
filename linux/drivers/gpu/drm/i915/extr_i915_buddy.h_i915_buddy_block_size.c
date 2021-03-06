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
typedef  int u64 ;
struct i915_buddy_mm {int chunk_size; } ;
struct i915_buddy_block {int dummy; } ;

/* Variables and functions */
 int i915_buddy_block_order (struct i915_buddy_block*) ; 

__attribute__((used)) static inline u64
i915_buddy_block_size(struct i915_buddy_mm *mm,
		      struct i915_buddy_block *block)
{
	return mm->chunk_size << i915_buddy_block_order(block);
}