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
struct sdhci_fdt_softc {int wp_inverted; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 struct sdhci_fdt_softc* device_get_softc (int /*<<< orphan*/ ) ; 
 int sdhci_generic_get_ro (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
sdhci_fdt_get_ro(device_t bus, device_t dev)
{
	struct sdhci_fdt_softc *sc = device_get_softc(bus);

	return (sdhci_generic_get_ro(bus, dev) ^ sc->wp_inverted);
}