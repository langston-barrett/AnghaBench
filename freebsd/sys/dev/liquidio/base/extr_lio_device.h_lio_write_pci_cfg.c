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
typedef  int /*<<< orphan*/  uint32_t ;
struct octeon_device {int /*<<< orphan*/  device; } ;

/* Variables and functions */
 int /*<<< orphan*/  pci_write_config (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline void
lio_write_pci_cfg(struct octeon_device *oct, uint32_t reg, uint32_t value)
{

	pci_write_config(oct->device, reg, value, 4);
}