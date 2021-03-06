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
struct tegra124_car_softc {int /*<<< orphan*/  clkdom; } ;

/* Variables and functions */
 int /*<<< orphan*/  config_utmi_pll (struct tegra124_car_softc*) ; 
 int nitems (scalar_t__) ; 
 int /*<<< orphan*/  panic (char*) ; 
 scalar_t__ pll_clks ; 
 int pll_register (int /*<<< orphan*/ ,scalar_t__) ; 

void
tegra124_init_plls(struct tegra124_car_softc *sc)
{
	int i, rv;

	for (i = 0; i < nitems(pll_clks); i++) {
		rv = pll_register(sc->clkdom, pll_clks + i);
		if (rv != 0)
			panic("pll_register failed");
	}
	config_utmi_pll(sc);

}