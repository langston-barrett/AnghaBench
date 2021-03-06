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
struct cache_entry_ {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
entries_qsort_cmp_func(const void *e1, const void *e2)
{

	assert(e1 != NULL);
	assert(e2 != NULL);

	return (strcmp((*(struct cache_entry_ const **)e1)->name,
		(*(struct cache_entry_ const **)e2)->name));
}