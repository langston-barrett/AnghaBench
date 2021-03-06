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
typedef  int /*<<< orphan*/  svn_wc_conflict_version_t ;
typedef  int /*<<< orphan*/  svn_revnum_t ;
typedef  int /*<<< orphan*/  svn_node_kind_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 int /*<<< orphan*/ * svn_wc_conflict_version_create2 (char const*,int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

svn_wc_conflict_version_t *
svn_wc_conflict_version_create(const char *repos_url,
                               const char *path_in_repos,
                               svn_revnum_t peg_rev,
                               svn_node_kind_t node_kind,
                               apr_pool_t *pool)
{
  return svn_wc_conflict_version_create2(repos_url, NULL, path_in_repos,
                                         peg_rev, node_kind, pool);
}