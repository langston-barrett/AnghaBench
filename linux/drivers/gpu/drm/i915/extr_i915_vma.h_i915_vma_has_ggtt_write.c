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
struct i915_vma {int flags; } ;

/* Variables and functions */
 int I915_VMA_GGTT_WRITE ; 

__attribute__((used)) static inline bool i915_vma_has_ggtt_write(const struct i915_vma *vma)
{
	return vma->flags & I915_VMA_GGTT_WRITE;
}