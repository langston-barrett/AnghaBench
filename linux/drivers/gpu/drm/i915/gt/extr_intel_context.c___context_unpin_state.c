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
struct i915_vma {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __i915_vma_unpin (struct i915_vma*) ; 
 int /*<<< orphan*/  i915_vma_make_shrinkable (struct i915_vma*) ; 

__attribute__((used)) static void __context_unpin_state(struct i915_vma *vma)
{
	__i915_vma_unpin(vma);
	i915_vma_make_shrinkable(vma);
}