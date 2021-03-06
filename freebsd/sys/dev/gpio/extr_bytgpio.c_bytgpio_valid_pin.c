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
struct bytgpio_softc {int sc_npins; int /*<<< orphan*/ * sc_mem_res; } ;

/* Variables and functions */
 int EINVAL ; 

__attribute__((used)) static int
bytgpio_valid_pin(struct bytgpio_softc *sc, int pin)
{

	if (pin >= sc->sc_npins || sc->sc_mem_res == NULL)
		return (EINVAL);

	return (0);
}