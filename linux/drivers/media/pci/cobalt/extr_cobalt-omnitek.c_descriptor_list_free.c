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
struct sg_dma_desc_info {int /*<<< orphan*/ * virt; int /*<<< orphan*/  bus; int /*<<< orphan*/  size; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  dma_free_coherent (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void descriptor_list_free(struct sg_dma_desc_info *desc)
{
	if (desc->virt)
		dma_free_coherent(desc->dev, desc->size,
				  desc->virt, desc->bus);
	desc->virt = NULL;
}