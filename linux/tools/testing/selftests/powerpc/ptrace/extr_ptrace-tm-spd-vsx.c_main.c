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
 int /*<<< orphan*/  ptrace_tm_spd_vsx ; 
 int test_harness (int /*<<< orphan*/ ,char*) ; 

int main(int argc, char *argv[])
{
	return test_harness(ptrace_tm_spd_vsx, "ptrace_tm_spd_vsx");
}