#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/ * mon_grouping; } ;

/* Variables and functions */
 int /*<<< orphan*/  free (char*) ; 
 TYPE_1__ mon ; 

void
reset_monetary_group(void)
{
	free((char *)mon.mon_grouping);
	mon.mon_grouping = NULL;
}