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
typedef  TYPE_1__* bus_dmamap_t ;
typedef  int /*<<< orphan*/  bus_dma_tag_t ;
struct TYPE_3__ {int /*<<< orphan*/  dm_flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMF_LOADED ; 

__attribute__((used)) static void
nexus_dmamap_unload(bus_dma_tag_t dmat, bus_dmamap_t map)
{

	map->dm_flags &= ~DMF_LOADED;
}