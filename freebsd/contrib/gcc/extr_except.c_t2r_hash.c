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
typedef  int /*<<< orphan*/  tree ;
typedef  int /*<<< orphan*/  hashval_t ;

/* Variables and functions */
 int /*<<< orphan*/  TREE_HASH (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TREE_PURPOSE (int /*<<< orphan*/ ) ; 

__attribute__((used)) static hashval_t
t2r_hash (const void *pentry)
{
  tree entry = (tree) pentry;
  return TREE_HASH (TREE_PURPOSE (entry));
}