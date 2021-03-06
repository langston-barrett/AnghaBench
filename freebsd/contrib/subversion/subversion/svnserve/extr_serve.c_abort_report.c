#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  svn_ra_svn_conn_t ;
typedef  int /*<<< orphan*/  svn_ra_svn__list_t ;
typedef  int /*<<< orphan*/  svn_error_t ;
struct TYPE_2__ {int /*<<< orphan*/  report_baton; } ;
typedef  TYPE_1__ report_driver_baton_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 int /*<<< orphan*/ * SVN_NO_ERROR ; 
 int /*<<< orphan*/  svn_error_clear (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  svn_repos_abort_report (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static svn_error_t *
abort_report(svn_ra_svn_conn_t *conn,
             apr_pool_t *pool,
             svn_ra_svn__list_t *params,
             void *baton)
{
  report_driver_baton_t *b = baton;

  /* No arguments to parse. */
  svn_error_clear(svn_repos_abort_report(b->report_baton, pool));
  return SVN_NO_ERROR;
}