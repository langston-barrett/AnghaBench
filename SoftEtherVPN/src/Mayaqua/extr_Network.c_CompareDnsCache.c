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
struct TYPE_2__ {int /*<<< orphan*/  HostName; } ;
typedef  TYPE_1__ DNSCACHE ;

/* Variables and functions */
 int StrCmpi (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int CompareDnsCache(void *p1, void *p2)
{
	DNSCACHE *c1, *c2;
	if (p1 == NULL || p2 == NULL)
	{
		return 0;
	}
	c1 = *(DNSCACHE **)p1;
	c2 = *(DNSCACHE **)p2;
	if (c1 == NULL || c2 == NULL)
	{
		return 0;
	}

	return StrCmpi(c1->HostName, c2->HostName);
}