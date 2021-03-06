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
typedef  scalar_t__ u8 ;
typedef  int u32 ;
struct radeon_device {int dummy; } ;
struct TYPE_3__ {scalar_t__ McArbBurstTime; void* McArbDramTiming2; void* McArbDramTiming; } ;
typedef  TYPE_1__ SMU7_Discrete_MCArbDramTimingTableEntry ;

/* Variables and functions */
 int /*<<< orphan*/  MC_ARB_BURST_TIME ; 
 int /*<<< orphan*/  MC_ARB_DRAM_TIMING ; 
 int /*<<< orphan*/  MC_ARB_DRAM_TIMING2 ; 
 int RREG32 (int /*<<< orphan*/ ) ; 
 int STATE0_MASK ; 
 int /*<<< orphan*/  ci_register_patching_mc_arb (struct radeon_device*,int,int,int*) ; 
 void* cpu_to_be32 (int) ; 
 int /*<<< orphan*/  radeon_atom_set_engine_dram_timings (struct radeon_device*,int,int) ; 

__attribute__((used)) static int ci_populate_memory_timing_parameters(struct radeon_device *rdev,
						u32 sclk,
						u32 mclk,
						SMU7_Discrete_MCArbDramTimingTableEntry *arb_regs)
{
	u32 dram_timing;
	u32 dram_timing2;
	u32 burst_time;

	radeon_atom_set_engine_dram_timings(rdev, sclk, mclk);

	dram_timing  = RREG32(MC_ARB_DRAM_TIMING);
	dram_timing2 = RREG32(MC_ARB_DRAM_TIMING2);
	burst_time = RREG32(MC_ARB_BURST_TIME) & STATE0_MASK;

	ci_register_patching_mc_arb(rdev, sclk, mclk, &dram_timing2);

	arb_regs->McArbDramTiming  = cpu_to_be32(dram_timing);
	arb_regs->McArbDramTiming2 = cpu_to_be32(dram_timing2);
	arb_regs->McArbBurstTime = (u8)burst_time;

	return 0;
}