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
struct wined3d_fence {scalar_t__ context; } ;

/* Variables and functions */
 int /*<<< orphan*/  context_free_fence (struct wined3d_fence*) ; 

__attribute__((used)) static void wined3d_fence_free(struct wined3d_fence *fence)
{
    if (fence->context)
        context_free_fence(fence);
}