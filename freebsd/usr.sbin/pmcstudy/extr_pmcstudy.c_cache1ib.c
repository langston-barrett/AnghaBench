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
struct counters {double* vals; double sum; } ;

/* Variables and functions */
 struct counters* find_counter (struct counters*,char*) ; 
 int printf (char*,double) ; 

__attribute__((used)) static int
cache1ib(struct counters *cpu, int pos)
{
	/*  9  - (MEM_LOAD_UOPS_L3_MISS_RETIRED.LCOAL_DRAM * 180) / CPU_CLK_UNHALTED.THREAD_P (thresh >= .2) */
	int ret;
	struct counters *mem;
	struct counters *unhalt;
	double con, un, me, res;

	con = 180.0;
	unhalt = find_counter(cpu, "CPU_CLK_UNHALTED.THREAD_P");
	mem = find_counter(cpu, "MEM_LOAD_UOPS_LLC_MISS_RETIRED.LOCAL_DRAM");
	if (pos != -1) {
		me = mem->vals[pos] * 1.0;
		un = unhalt->vals[pos] * 1.0;
	} else {
		me = mem->sum * 1.0;
		un = unhalt->sum * 1.0;
	}
	res = (me * con)/un;
	ret = printf("%1.3f", res);
	return(ret);
}