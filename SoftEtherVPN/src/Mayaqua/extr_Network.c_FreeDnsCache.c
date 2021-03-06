#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ UINT ;
struct TYPE_4__ {struct TYPE_4__* HostName; } ;
typedef  TYPE_1__ DNSCACHE ;

/* Variables and functions */
 int /*<<< orphan*/ * DnsCache ; 
 int /*<<< orphan*/  Free (TYPE_1__*) ; 
 TYPE_1__* LIST_DATA (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ LIST_NUM (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  LockDnsCache () ; 
 int /*<<< orphan*/  ReleaseList (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  UnlockDnsCache () ; 

void FreeDnsCache()
{
	LockDnsCache();
	{
		DNSCACHE *c;
		UINT i;
		for (i = 0;i < LIST_NUM(DnsCache);i++)
		{
			// Release the memory for the entry
			c = LIST_DATA(DnsCache, i);
			Free(c->HostName);
			Free(c);
		}
	}
	UnlockDnsCache();

	// Release the list
	ReleaseList(DnsCache);
	DnsCache = NULL;
}