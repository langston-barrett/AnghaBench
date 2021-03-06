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
struct pci_dev {int dummy; } ;

/* Variables and functions */
 int PCI_EXP_FLAGS_VERS ; 
 int pcie_caps_reg (struct pci_dev const*) ; 

__attribute__((used)) static inline int pcie_cap_version(const struct pci_dev *dev)
{
	return pcie_caps_reg(dev) & PCI_EXP_FLAGS_VERS;
}