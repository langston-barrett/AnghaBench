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
typedef  TYPE_1__* tpa_p ;
struct TYPE_3__ {int num_trees; } ;

/* Variables and functions */

__attribute__((used)) static inline int
tpa_num_trees (tpa_p tpa)
{
  return tpa->num_trees;
}