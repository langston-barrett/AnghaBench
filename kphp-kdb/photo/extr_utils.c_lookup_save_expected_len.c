#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int n; int /*<<< orphan*/  new_v; } ;
typedef  TYPE_1__ lookup ;

/* Variables and functions */
 int map_int_int_used (int /*<<< orphan*/ *) ; 

int lookup_save_expected_len (lookup *l) {
  return map_int_int_used (&l->new_v) + l->n;
}