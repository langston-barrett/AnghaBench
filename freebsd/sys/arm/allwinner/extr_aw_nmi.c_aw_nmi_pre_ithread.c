#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct intr_irqsrc {int dummy; } ;
struct aw_nmi_softc {TYPE_1__* cfg; } ;
typedef  int /*<<< orphan*/  device_t ;
struct TYPE_2__ {int /*<<< orphan*/  pending_reg; } ;

/* Variables and functions */
 int /*<<< orphan*/  NMI_IRQ_ACK ; 
 int /*<<< orphan*/  SC_NMI_WRITE (struct aw_nmi_softc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  aw_nmi_disable_intr (int /*<<< orphan*/ ,struct intr_irqsrc*) ; 
 struct aw_nmi_softc* device_get_softc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
aw_nmi_pre_ithread(device_t dev, struct intr_irqsrc *isrc)
{
	struct aw_nmi_softc *sc;

	sc = device_get_softc(dev);
	aw_nmi_disable_intr(dev, isrc);
	SC_NMI_WRITE(sc, sc->cfg->pending_reg, NMI_IRQ_ACK);
}