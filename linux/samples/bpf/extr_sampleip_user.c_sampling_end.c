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

/* Variables and functions */
 int /*<<< orphan*/  close (int) ; 
 int nr_cpus ; 

__attribute__((used)) static void sampling_end(int *pmu_fd)
{
	int i;

	for (i = 0; i < nr_cpus; i++)
		close(pmu_fd[i]);
}