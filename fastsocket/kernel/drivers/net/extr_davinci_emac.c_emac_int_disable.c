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
struct emac_priv {scalar_t__ version; } ;

/* Variables and functions */
 int /*<<< orphan*/  EMAC_CTRL_EWCTL ; 
 int /*<<< orphan*/  EMAC_DM646X_CMRXINTEN ; 
 int /*<<< orphan*/  EMAC_DM646X_CMTXINTEN ; 
 scalar_t__ EMAC_VERSION_2 ; 
 int /*<<< orphan*/  emac_ctrl_write (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 

__attribute__((used)) static void emac_int_disable(struct emac_priv *priv)
{
	if (priv->version == EMAC_VERSION_2) {
		unsigned long flags;

		local_irq_save(flags);

		/* Program C0_Int_En to zero to turn off
		* interrupts to the CPU */
		emac_ctrl_write(EMAC_DM646X_CMRXINTEN, 0x0);
		emac_ctrl_write(EMAC_DM646X_CMTXINTEN, 0x0);
		/* NOTE: Rx Threshold and Misc interrupts are not disabled */

		local_irq_restore(flags);

	} else {
		/* Set DM644x control registers for interrupt control */
		emac_ctrl_write(EMAC_CTRL_EWCTL, 0x0);
	}
}