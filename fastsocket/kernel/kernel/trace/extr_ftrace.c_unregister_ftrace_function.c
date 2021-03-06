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
struct ftrace_ops {int dummy; } ;

/* Variables and functions */
 int __unregister_ftrace_function (struct ftrace_ops*) ; 
 int /*<<< orphan*/  ftrace_lock ; 
 int /*<<< orphan*/  ftrace_shutdown (struct ftrace_ops*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

int unregister_ftrace_function(struct ftrace_ops *ops)
{
	int ret;

	mutex_lock(&ftrace_lock);
	ret = __unregister_ftrace_function(ops);
	if (!ret)
		ftrace_shutdown(ops, 0);
	mutex_unlock(&ftrace_lock);

	return ret;
}