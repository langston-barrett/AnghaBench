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
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  gfp_t ;
typedef  scalar_t__ dma_addr_t ;

/* Variables and functions */
 scalar_t__ __get_free_pages (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_order (size_t) ; 
 scalar_t__ virt_to_phys (void*) ; 

__attribute__((used)) static void *pa11_dma_alloc_noncoherent(struct device *dev, size_t size,
					  dma_addr_t *dma_handle, gfp_t flag)
{
	void *addr;

	addr = (void *)__get_free_pages(flag, get_order(size));
	if (addr)
		*dma_handle = (dma_addr_t)virt_to_phys(addr);

	return addr;
}