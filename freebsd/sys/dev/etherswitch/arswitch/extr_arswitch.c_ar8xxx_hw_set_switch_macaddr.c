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
struct ether_addr {int dummy; } ;
struct arswitch_softc {int dummy; } ;

/* Variables and functions */
 int ENXIO ; 

__attribute__((used)) static int
ar8xxx_hw_set_switch_macaddr(struct arswitch_softc *sc,
    const struct ether_addr *ea)
{

	return (ENXIO);
}