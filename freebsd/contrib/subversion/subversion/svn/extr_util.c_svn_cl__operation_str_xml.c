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
typedef  int /*<<< orphan*/  svn_wc_operation_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 int /*<<< orphan*/  map_wc_operation_xml ; 
 char const* svn_token__to_word (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

const char *
svn_cl__operation_str_xml(svn_wc_operation_t operation, apr_pool_t *pool)
{
  return svn_token__to_word(map_wc_operation_xml, operation);
}