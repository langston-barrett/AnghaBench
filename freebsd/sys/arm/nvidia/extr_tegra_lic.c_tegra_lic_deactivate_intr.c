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
struct tegra_lic_sc {int /*<<< orphan*/  parent; } ;
struct resource {int dummy; } ;
struct intr_map_data {int dummy; } ;
struct intr_irqsrc {int dummy; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int PIC_DEACTIVATE_INTR (int /*<<< orphan*/ ,struct intr_irqsrc*,struct resource*,struct intr_map_data*) ; 
 struct tegra_lic_sc* device_get_softc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
tegra_lic_deactivate_intr(device_t dev, struct intr_irqsrc *isrc,
    struct resource *res, struct intr_map_data *data)
{
	struct tegra_lic_sc *sc = device_get_softc(dev);

	return (PIC_DEACTIVATE_INTR(sc->parent, isrc, res, data));
}