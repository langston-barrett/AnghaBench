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
struct device {int dummy; } ;
struct bnx2x {int /*<<< orphan*/  flags; TYPE_1__* pdev; } ;
struct TYPE_2__ {struct device dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMA_BIT_MASK (int) ; 
 int EIO ; 
 int /*<<< orphan*/  USING_DAC_FLAG ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 scalar_t__ dma_set_coherent_mask (struct device*,int /*<<< orphan*/ ) ; 
 scalar_t__ dma_set_mask (struct device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int bnx2x_set_coherency_mask(struct bnx2x *bp)
{
	struct device *dev = &bp->pdev->dev;

	if (dma_set_mask(dev, DMA_BIT_MASK(64)) == 0) {
		bp->flags |= USING_DAC_FLAG;
		if (dma_set_coherent_mask(dev, DMA_BIT_MASK(64)) != 0) {
			dev_err(dev, "dma_set_coherent_mask failed, aborting\n");
			return -EIO;
		}
	} else if (dma_set_mask(dev, DMA_BIT_MASK(32)) != 0) {
		dev_err(dev, "System does not support DMA, aborting\n");
		return -EIO;
	}

	return 0;
}