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
typedef  int /*<<< orphan*/  loff_t ;

/* Variables and functions */
 void* t_start (struct seq_file*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void *t_next(struct seq_file *m, void * v, loff_t *pos)
{
	(*pos)++;
	return t_start(m, pos);
}