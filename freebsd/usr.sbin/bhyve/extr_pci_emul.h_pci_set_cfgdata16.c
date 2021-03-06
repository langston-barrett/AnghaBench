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
typedef  int /*<<< orphan*/  uint16_t ;
struct pci_devinst {scalar_t__ pi_cfgdata; } ;

/* Variables and functions */
 int PCI_REGMAX ; 
 int /*<<< orphan*/  assert (int) ; 

__attribute__((used)) static __inline void 
pci_set_cfgdata16(struct pci_devinst *pi, int offset, uint16_t val)
{
	assert(offset <= (PCI_REGMAX - 1) && (offset & 1) == 0);
	*(uint16_t *)(pi->pi_cfgdata + offset) = val;
}