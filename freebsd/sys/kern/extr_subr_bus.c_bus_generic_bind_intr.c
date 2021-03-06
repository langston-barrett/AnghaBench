#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct resource {int dummy; } ;
typedef  TYPE_1__* device_t ;
struct TYPE_5__ {scalar_t__ parent; } ;

/* Variables and functions */
 int BUS_BIND_INTR (scalar_t__,TYPE_1__*,struct resource*,int) ; 
 int EINVAL ; 

int
bus_generic_bind_intr(device_t dev, device_t child, struct resource *irq,
    int cpu)
{

	/* Propagate up the bus hierarchy until someone handles it. */
	if (dev->parent)
		return (BUS_BIND_INTR(dev->parent, child, irq, cpu));
	return (EINVAL);
}