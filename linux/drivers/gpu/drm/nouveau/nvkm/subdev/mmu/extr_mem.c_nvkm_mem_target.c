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
struct nvkm_memory {int dummy; } ;
typedef  enum nvkm_memory_target { ____Placeholder_nvkm_memory_target } nvkm_memory_target ;
struct TYPE_2__ {int target; } ;

/* Variables and functions */
 TYPE_1__* nvkm_mem (struct nvkm_memory*) ; 

__attribute__((used)) static enum nvkm_memory_target
nvkm_mem_target(struct nvkm_memory *memory)
{
	return nvkm_mem(memory)->target;
}