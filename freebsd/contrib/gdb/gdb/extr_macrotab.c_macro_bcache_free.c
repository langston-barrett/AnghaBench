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
struct macro_table {int /*<<< orphan*/  bcache; } ;

/* Variables and functions */
 int /*<<< orphan*/  gdb_assert (int) ; 
 int /*<<< orphan*/  xfree (void*) ; 

__attribute__((used)) static void
macro_bcache_free (struct macro_table *t, void *obj)
{
  gdb_assert (! t->bcache);
  xfree (obj);
}