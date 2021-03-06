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
typedef  int /*<<< orphan*/  svn_error_t ;
struct ev2_baton {int /*<<< orphan*/  inner; } ;
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 int /*<<< orphan*/  SVN_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * SVN_NO_ERROR ; 
 int /*<<< orphan*/  svn_editor_abort (int /*<<< orphan*/ ) ; 

__attribute__((used)) static svn_error_t *
abort_cb(void *baton,
         apr_pool_t *scratch_pool)
{
  struct ev2_baton *eb = baton;

  SVN_ERR(svn_editor_abort(eb->inner));
  return SVN_NO_ERROR;
}