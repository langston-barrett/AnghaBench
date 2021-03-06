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
typedef  int /*<<< orphan*/  u32 ;
struct radeon_device {int /*<<< orphan*/  smc_idx_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  SMC_IND_DATA_0 ; 
 int /*<<< orphan*/  WREG32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ci_set_smc_sram_address (struct radeon_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

int ci_write_smc_sram_dword(struct radeon_device *rdev,
			    u32 smc_address, u32 value, u32 limit)
{
	unsigned long flags;
	int ret;

	spin_lock_irqsave(&rdev->smc_idx_lock, flags);
	ret = ci_set_smc_sram_address(rdev, smc_address, limit);
	if (ret == 0)
		WREG32(SMC_IND_DATA_0, value);
	spin_unlock_irqrestore(&rdev->smc_idx_lock, flags);

	return ret;
}