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
typedef  scalar_t__ tree ;

/* Variables and functions */
 scalar_t__ TREE_PURPOSE (scalar_t__) ; 

__attribute__((used)) static int
t2r_eq (const void *pentry, const void *pdata)
{
  tree entry = (tree) pentry;
  tree data = (tree) pdata;

  return TREE_PURPOSE (entry) == data;
}