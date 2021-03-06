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
struct usb_ether {int /*<<< orphan*/  ue_dev; } ;
struct muge_softc {int sc_flags; int /*<<< orphan*/  sc_ue; } ;
struct mii_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MA_OWNED ; 
 int MUGE_FLAG_LINK ; 
 int /*<<< orphan*/  MUGE_LOCK_ASSERT (struct muge_softc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lan78xx_miibus_statchg (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mii_tick (struct mii_data*) ; 
 int /*<<< orphan*/  muge_start (struct usb_ether*) ; 
 struct mii_data* uether_getmii (int /*<<< orphan*/ *) ; 
 struct muge_softc* uether_getsc (struct usb_ether*) ; 

__attribute__((used)) static void
muge_tick(struct usb_ether *ue)
{

	struct muge_softc *sc = uether_getsc(ue);
	struct mii_data *mii = uether_getmii(&sc->sc_ue);

	MUGE_LOCK_ASSERT(sc, MA_OWNED);

	mii_tick(mii);
	if ((sc->sc_flags & MUGE_FLAG_LINK) == 0) {
		lan78xx_miibus_statchg(ue->ue_dev);
		if ((sc->sc_flags & MUGE_FLAG_LINK) != 0)
			muge_start(ue);
	}
}