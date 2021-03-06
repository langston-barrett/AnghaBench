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
typedef  int /*<<< orphan*/  git_reference ;

/* Variables and functions */
 int /*<<< orphan*/  FETCH_HEAD_EXPLICIT_DATA ; 
 int /*<<< orphan*/  GIT_BRANCH_ALL ; 
 int /*<<< orphan*/  cl_assert_equal_i (size_t,size_t) ; 
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 size_t count_references () ; 
 int /*<<< orphan*/  fetchhead_test_clone () ; 
 int /*<<< orphan*/  fetchhead_test_fetch (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  g_repo ; 
 int /*<<< orphan*/  git_branch_lookup (int /*<<< orphan*/ **,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 

void test_online_fetchhead__empty_dst_refspec_creates_no_branch(void)
{
	git_reference *ref;
	size_t refs;

	fetchhead_test_clone();
	refs = count_references();

	fetchhead_test_fetch("refs/heads/first-merge", FETCH_HEAD_EXPLICIT_DATA);
	cl_git_fail(git_branch_lookup(&ref, g_repo, "first-merge", GIT_BRANCH_ALL));

	cl_assert_equal_i(refs, count_references());
}