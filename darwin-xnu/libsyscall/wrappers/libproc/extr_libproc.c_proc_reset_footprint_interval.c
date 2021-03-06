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
typedef  int /*<<< orphan*/  pid_t ;

/* Variables and functions */
 scalar_t__ FOOTPRINT_INTERVAL_RESET ; 
 int /*<<< orphan*/  RLIMIT_FOOTPRINT_INTERVAL ; 
 int proc_rlimit_control (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*) ; 

int
proc_reset_footprint_interval(pid_t pid)
{
	return (proc_rlimit_control(pid, RLIMIT_FOOTPRINT_INTERVAL, (void *)(uintptr_t)FOOTPRINT_INTERVAL_RESET));
}