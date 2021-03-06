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
struct bcm_pwm_softc {scalar_t__ sc_mem_res; scalar_t__ mode2; scalar_t__ mode; } ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int /*<<< orphan*/  SYS_RES_MEMORY ; 
 int /*<<< orphan*/  bcm_pwm_reconf (struct bcm_pwm_softc*) ; 
 int /*<<< orphan*/  bus_generic_detach (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bus_release_resource (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 struct bcm_pwm_softc* device_get_softc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
bcm_pwm_detach(device_t dev)
{
	struct bcm_pwm_softc *sc;

	bus_generic_detach(dev);

	sc = device_get_softc(dev);
	sc->mode = 0;
	sc->mode2 = 0;
	(void)bcm_pwm_reconf(sc);
	if (sc->sc_mem_res)
		bus_release_resource(dev, SYS_RES_MEMORY, 0, sc->sc_mem_res);

	return (0);
}