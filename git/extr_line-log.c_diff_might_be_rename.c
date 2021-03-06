#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int nr; TYPE_1__** queue; } ;
struct TYPE_3__ {int /*<<< orphan*/  one; } ;

/* Variables and functions */
 int /*<<< orphan*/  DIFF_FILE_VALID (int /*<<< orphan*/ ) ; 
 TYPE_2__ diff_queued_diff ; 

__attribute__((used)) static inline int diff_might_be_rename(void)
{
	int i;
	for (i = 0; i < diff_queued_diff.nr; i++)
		if (!DIFF_FILE_VALID(diff_queued_diff.queue[i]->one)) {
			/* fprintf(stderr, "diff_might_be_rename found creation of: %s\n", */
			/* 	diff_queued_diff.queue[i]->two->path); */
			return 1;
		}
	return 0;
}