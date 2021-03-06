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
struct brcmf_bus {int /*<<< orphan*/  dev; TYPE_1__* ops; } ;
struct TYPE_2__ {void (* debugfs_create ) (int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 void stub1 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline
void brcmf_bus_debugfs_create(struct brcmf_bus *bus)
{
	if (!bus->ops->debugfs_create)
		return;

	return bus->ops->debugfs_create(bus->dev);
}