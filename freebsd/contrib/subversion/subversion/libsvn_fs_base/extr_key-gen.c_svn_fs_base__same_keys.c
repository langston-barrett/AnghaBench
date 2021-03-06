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
typedef  int svn_boolean_t ;

/* Variables and functions */
 int FALSE ; 
 int TRUE ; 
 scalar_t__ strcmp (char const*,char const*) ; 

svn_boolean_t
svn_fs_base__same_keys(const char *a, const char *b)
{
  if (! (a || b))
    return TRUE;
  if (a && (! b))
    return FALSE;
  if ((! a) && b)
    return FALSE;
  return (strcmp(a, b) == 0);
}