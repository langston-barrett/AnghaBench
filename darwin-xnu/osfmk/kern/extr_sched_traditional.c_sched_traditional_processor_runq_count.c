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
typedef  int /*<<< orphan*/  processor_t ;
struct TYPE_2__ {int count; } ;

/* Variables and functions */
 TYPE_1__* runq_for_processor (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
sched_traditional_processor_runq_count(processor_t processor)
{
	return runq_for_processor(processor)->count;
}