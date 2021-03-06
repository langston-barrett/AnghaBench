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

/* Variables and functions */
 int /*<<< orphan*/  atomic_notifier_chain_register (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  new_thread_handler () ; 
 int /*<<< orphan*/  panic_exit_notifier ; 
 int /*<<< orphan*/  panic_notifier_list ; 
 int /*<<< orphan*/  uml_postsetup () ; 

void uml_finishsetup(void)
{
	atomic_notifier_chain_register(&panic_notifier_list,
				       &panic_exit_notifier);

	uml_postsetup();

	new_thread_handler();
}