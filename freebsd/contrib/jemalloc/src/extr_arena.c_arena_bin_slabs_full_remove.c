#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  extent_t ;
struct TYPE_3__ {int /*<<< orphan*/  slabs_full; } ;
typedef  TYPE_1__ bin_t ;
typedef  int /*<<< orphan*/  arena_t ;

/* Variables and functions */
 scalar_t__ arena_is_auto (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  extent_list_remove (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
arena_bin_slabs_full_remove(arena_t *arena, bin_t *bin, extent_t *slab) {
	if (arena_is_auto(arena)) {
		return;
	}
	extent_list_remove(&bin->slabs_full, slab);
}