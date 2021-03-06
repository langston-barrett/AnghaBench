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
struct netfs_state {int /*<<< orphan*/ * whead; int /*<<< orphan*/  wait; } ;

/* Variables and functions */
 int /*<<< orphan*/  remove_wait_queue (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void netfs_poll_exit(struct netfs_state *st)
{
	if (st->whead) {
		remove_wait_queue(st->whead, &st->wait);
		st->whead = NULL;
	}
}