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
struct cpu_hw_events {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  intel_cpuc_finish (struct cpu_hw_events*) ; 
 int /*<<< orphan*/  kfree (struct cpu_hw_events*) ; 

__attribute__((used)) static void free_fake_cpuc(struct cpu_hw_events *cpuc)
{
	intel_cpuc_finish(cpuc);
	kfree(cpuc);
}