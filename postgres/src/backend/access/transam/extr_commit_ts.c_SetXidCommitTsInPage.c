#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  TransactionId ;
typedef  int /*<<< orphan*/  TimestampTz ;
struct TYPE_5__ {TYPE_1__* shared; } ;
struct TYPE_4__ {int* page_dirty; } ;
typedef  int /*<<< orphan*/  RepOriginId ;

/* Variables and functions */
 int /*<<< orphan*/  CommitTsControlLock ; 
 TYPE_2__* CommitTsCtl ; 
 int /*<<< orphan*/  LWLockAcquire (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LWLockRelease (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LW_EXCLUSIVE ; 
 int SimpleLruReadPage (TYPE_2__*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TransactionIdSetCommitTs (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void
SetXidCommitTsInPage(TransactionId xid, int nsubxids,
					 TransactionId *subxids, TimestampTz ts,
					 RepOriginId nodeid, int pageno)
{
	int			slotno;
	int			i;

	LWLockAcquire(CommitTsControlLock, LW_EXCLUSIVE);

	slotno = SimpleLruReadPage(CommitTsCtl, pageno, true, xid);

	TransactionIdSetCommitTs(xid, ts, nodeid, slotno);
	for (i = 0; i < nsubxids; i++)
		TransactionIdSetCommitTs(subxids[i], ts, nodeid, slotno);

	CommitTsCtl->shared->page_dirty[slotno] = true;

	LWLockRelease(CommitTsControlLock);
}