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
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/ * g_config ; 
 int /*<<< orphan*/ * g_repo ; 
 int /*<<< orphan*/  git_config_free (int /*<<< orphan*/ *) ; 

void test_config_rename__cleanup(void)
{
	git_config_free(g_config);
	g_config = NULL;

	cl_git_sandbox_cleanup();
	g_repo = NULL;
}