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
struct trace_event_call {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  down_write (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  event_mutex ; 
 int /*<<< orphan*/  lockdep_assert_held (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int probe_remove_event_call (struct trace_event_call*) ; 
 int /*<<< orphan*/  trace_event_sem ; 
 int /*<<< orphan*/  trace_types_lock ; 
 int /*<<< orphan*/  up_write (int /*<<< orphan*/ *) ; 

int trace_remove_event_call(struct trace_event_call *call)
{
	int ret;

	lockdep_assert_held(&event_mutex);

	mutex_lock(&trace_types_lock);
	down_write(&trace_event_sem);
	ret = probe_remove_event_call(call);
	up_write(&trace_event_sem);
	mutex_unlock(&trace_types_lock);

	return ret;
}