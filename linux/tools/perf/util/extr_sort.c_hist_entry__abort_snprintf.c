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
struct hist_entry {TYPE_2__* branch_info; } ;
struct TYPE_3__ {scalar_t__ abort; } ;
struct TYPE_4__ {TYPE_1__ flags; } ;

/* Variables and functions */
 int repsep_snprintf (char*,size_t,char*,unsigned int,char const*) ; 

__attribute__((used)) static int hist_entry__abort_snprintf(struct hist_entry *he, char *bf,
				    size_t size, unsigned int width)
{
	static const char *out = "N/A";

	if (he->branch_info) {
		if (he->branch_info->flags.abort)
			out = "A";
		else
			out = ".";
	}

	return repsep_snprintf(bf, size, "%-*s", width, out);
}