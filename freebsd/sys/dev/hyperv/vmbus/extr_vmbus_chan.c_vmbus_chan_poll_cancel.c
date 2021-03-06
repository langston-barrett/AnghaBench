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
struct vmbus_channel {int dummy; } ;
struct task {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  TASK_INIT (struct task*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct vmbus_channel*) ; 
 int /*<<< orphan*/  vmbus_chan_poll_cancel_task ; 
 int /*<<< orphan*/  vmbus_chan_run_task (struct vmbus_channel*,struct task*) ; 

__attribute__((used)) static void
vmbus_chan_poll_cancel(struct vmbus_channel *chan)
{
	struct task poll_cancel;

	TASK_INIT(&poll_cancel, 0, vmbus_chan_poll_cancel_task, chan);
	vmbus_chan_run_task(chan, &poll_cancel);
}