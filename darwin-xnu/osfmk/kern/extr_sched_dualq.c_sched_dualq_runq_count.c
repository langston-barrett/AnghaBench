#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  processor_t ;
struct TYPE_4__ {int count; } ;
struct TYPE_3__ {int count; } ;

/* Variables and functions */
 TYPE_2__* dualq_bound_runq (int /*<<< orphan*/ ) ; 
 TYPE_1__* dualq_main_runq (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
sched_dualq_runq_count(processor_t processor)
{
	return dualq_main_runq(processor)->count + dualq_bound_runq(processor)->count;
}