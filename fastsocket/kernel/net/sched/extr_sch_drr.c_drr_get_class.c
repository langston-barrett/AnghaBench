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
struct drr_class {int /*<<< orphan*/  refcnt; } ;
struct Qdisc {int dummy; } ;

/* Variables and functions */
 struct drr_class* drr_find_class (struct Qdisc*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned long drr_get_class(struct Qdisc *sch, u32 classid)
{
	struct drr_class *cl = drr_find_class(sch, classid);

	if (cl != NULL)
		cl->refcnt++;

	return (unsigned long)cl;
}