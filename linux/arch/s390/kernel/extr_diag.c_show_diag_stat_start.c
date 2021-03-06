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
struct seq_file {int dummy; } ;
typedef  scalar_t__ loff_t ;

/* Variables and functions */
 scalar_t__ nr_cpu_ids ; 

__attribute__((used)) static void *show_diag_stat_start(struct seq_file *m, loff_t *pos)
{
	return *pos <= nr_cpu_ids ? (void *)((unsigned long) *pos + 1) : NULL;
}