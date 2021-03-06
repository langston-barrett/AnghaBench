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
typedef  int u8 ;
struct pci_dev {int irq; } ;

/* Variables and functions */

int pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
	switch (slot) {
	case 1:
		return 14;
	case 2:
		return 13;
	case 3:
		return 12;
	default:
		return dev->irq;
	}
}