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
struct ess_info {int /*<<< orphan*/  sb; } ;

/* Variables and functions */
 int port_rd (int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static int
ess_rd(struct ess_info *sc, int reg)
{
	return port_rd(sc->sb, reg, 1);
}