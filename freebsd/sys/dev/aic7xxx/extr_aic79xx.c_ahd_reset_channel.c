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
typedef  size_t u_int ;
struct ahd_tmode_tstate {struct ahd_tmode_lstate** enabled_luns; } ;
struct ahd_tmode_lstate {int dummy; } ;
struct ahd_softc {int flags; int features; int /*<<< orphan*/  reset_timer; struct ahd_tmode_tstate** enabled_targets; int /*<<< orphan*/ * pending_device; } ;
struct ahd_devinfo {int /*<<< orphan*/  channel; } ;

/* Variables and functions */
 int /*<<< orphan*/  AC_BUS_RESET ; 
 size_t AHD_MODE_SCSI ; 
 size_t AHD_NUM_LUNS ; 
 int AHD_RESET_POLL_ACTIVE ; 
 int AHD_TARGETROLE ; 
 int /*<<< orphan*/  AHD_TRANS_CUR ; 
 int AHD_WIDE ; 
 int /*<<< orphan*/  CAM_LUN_WILDCARD ; 
 int /*<<< orphan*/  CAM_SCSI_BUS_RESET ; 
 size_t CAM_TARGET_WILDCARD ; 
 size_t CURRFIFO ; 
 size_t CURRFIFO_1 ; 
 int /*<<< orphan*/  DFCNTRL ; 
 int /*<<< orphan*/  DFFSTAT ; 
 size_t ENBUSFREE ; 
 size_t ENSCSIRST ; 
 int /*<<< orphan*/  EVENT_TYPE_BUS_RESET ; 
 size_t HDMAEN ; 
 size_t HDMAENACK ; 
 int /*<<< orphan*/  MSG_EXT_WDTR_BUS_8_BIT ; 
 int /*<<< orphan*/  ROLE_UNKNOWN ; 
 int /*<<< orphan*/  SCB_LIST_NULL ; 
 size_t SCSIEN ; 
 int /*<<< orphan*/  SCSISEQ0 ; 
 int /*<<< orphan*/  SCSISEQ1 ; 
 int /*<<< orphan*/  SIMODE1 ; 
 int /*<<< orphan*/  TRUE ; 
 int ahd_abort_scbs (struct ahd_softc*,size_t,char,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ahd_clear_critical_section (struct ahd_softc*) ; 
 int /*<<< orphan*/  ahd_clear_fifo (struct ahd_softc*,int) ; 
 int /*<<< orphan*/  ahd_clear_intstat (struct ahd_softc*) ; 
 int /*<<< orphan*/  ahd_clear_msg_state (struct ahd_softc*) ; 
 int /*<<< orphan*/  ahd_compile_devinfo (struct ahd_devinfo*,size_t,size_t,int /*<<< orphan*/ ,char,int /*<<< orphan*/ ) ; 
 size_t ahd_inb (struct ahd_softc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ahd_outb (struct ahd_softc*,int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  ahd_pause (struct ahd_softc*) ; 
 int /*<<< orphan*/  ahd_queue_lstate_event (struct ahd_softc*,struct ahd_tmode_lstate*,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ahd_reset_current_bus (struct ahd_softc*) ; 
 int /*<<< orphan*/  ahd_reset_poll ; 
 int /*<<< orphan*/  ahd_restart (struct ahd_softc*) ; 
 int /*<<< orphan*/  ahd_run_tqinfifo (struct ahd_softc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ahd_send_async (struct ahd_softc*,int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ahd_send_lstate_events (struct ahd_softc*,struct ahd_tmode_lstate*) ; 
 int /*<<< orphan*/  ahd_set_modes (struct ahd_softc*,size_t,size_t) ; 
 int /*<<< orphan*/  ahd_set_syncrate (struct ahd_softc*,struct ahd_devinfo*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ahd_set_width (struct ahd_softc*,struct ahd_devinfo*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  aic_delay (int) ; 
 int /*<<< orphan*/  aic_freeze_simq (struct ahd_softc*) ; 
 int /*<<< orphan*/  aic_timer_reset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct ahd_softc*) ; 

int
ahd_reset_channel(struct ahd_softc *ahd, char channel, int initiate_reset)
{
	struct	ahd_devinfo devinfo;
	u_int	initiator;
	u_int	target;
	u_int	max_scsiid;
	int	found;
	u_int	fifo;
	u_int	next_fifo;

	ahd->pending_device = NULL;

	ahd_compile_devinfo(&devinfo,
			    CAM_TARGET_WILDCARD,
			    CAM_TARGET_WILDCARD,
			    CAM_LUN_WILDCARD,
			    channel, ROLE_UNKNOWN);
	ahd_pause(ahd);

	/* Make sure the sequencer is in a safe location. */
	ahd_clear_critical_section(ahd);

#ifdef AHD_TARGET_MODE
	if ((ahd->flags & AHD_TARGETROLE) != 0) {
		ahd_run_tqinfifo(ahd, /*paused*/TRUE);
	}
#endif
	ahd_set_modes(ahd, AHD_MODE_SCSI, AHD_MODE_SCSI);

	/*
	 * Disable selections so no automatic hardware
	 * functions will modify chip state.
	 */
	ahd_outb(ahd, SCSISEQ0, 0);
	ahd_outb(ahd, SCSISEQ1, 0);

	/*
	 * Safely shut down our DMA engines.  Always start with
	 * the FIFO that is not currently active (if any are
	 * actively connected).
	 */
	next_fifo = fifo = ahd_inb(ahd, DFFSTAT) & CURRFIFO;
	if (next_fifo > CURRFIFO_1)
		/* If disconneced, arbitrarily start with FIFO1. */
		next_fifo = fifo = 0;
	do {
		next_fifo ^= CURRFIFO_1;
		ahd_set_modes(ahd, next_fifo, next_fifo);
		ahd_outb(ahd, DFCNTRL,
			 ahd_inb(ahd, DFCNTRL) & ~(SCSIEN|HDMAEN));
		while ((ahd_inb(ahd, DFCNTRL) & HDMAENACK) != 0)
			aic_delay(10);
		/*
		 * Set CURRFIFO to the now inactive channel.
		 */
		ahd_set_modes(ahd, AHD_MODE_SCSI, AHD_MODE_SCSI);
		ahd_outb(ahd, DFFSTAT, next_fifo);
	} while (next_fifo != fifo);

	/*
	 * Reset the bus if we are initiating this reset
	 */
	ahd_clear_msg_state(ahd);
	ahd_outb(ahd, SIMODE1,
		 ahd_inb(ahd, SIMODE1) & ~(ENBUSFREE|ENSCSIRST));

	if (initiate_reset)
		ahd_reset_current_bus(ahd);

	ahd_clear_intstat(ahd);

	/*
	 * Clean up all the state information for the
	 * pending transactions on this bus.
	 */
	found = ahd_abort_scbs(ahd, CAM_TARGET_WILDCARD, channel,
			       CAM_LUN_WILDCARD, SCB_LIST_NULL,
			       ROLE_UNKNOWN, CAM_SCSI_BUS_RESET);

	/*
	 * Cleanup anything left in the FIFOs.
	 */
	ahd_clear_fifo(ahd, 0);
	ahd_clear_fifo(ahd, 1);

	/*
	 * Revert to async/narrow transfers until we renegotiate.
	 */
	max_scsiid = (ahd->features & AHD_WIDE) ? 15 : 7;
	for (target = 0; target <= max_scsiid; target++) {

		if (ahd->enabled_targets[target] == NULL)
			continue;
		for (initiator = 0; initiator <= max_scsiid; initiator++) {
			struct ahd_devinfo devinfo;

			ahd_compile_devinfo(&devinfo, target, initiator,
					    CAM_LUN_WILDCARD,
					    'A', ROLE_UNKNOWN);
			ahd_set_width(ahd, &devinfo, MSG_EXT_WDTR_BUS_8_BIT,
				      AHD_TRANS_CUR, /*paused*/TRUE);
			ahd_set_syncrate(ahd, &devinfo, /*period*/0,
					 /*offset*/0, /*ppr_options*/0,
					 AHD_TRANS_CUR, /*paused*/TRUE);
		}
	}

#ifdef AHD_TARGET_MODE
	max_scsiid = (ahd->features & AHD_WIDE) ? 15 : 7;

	/*
	 * Send an immediate notify ccb to all target more peripheral
	 * drivers affected by this action.
	 */
	for (target = 0; target <= max_scsiid; target++) {
		struct ahd_tmode_tstate* tstate;
		u_int lun;

		tstate = ahd->enabled_targets[target];
		if (tstate == NULL)
			continue;
		for (lun = 0; lun < AHD_NUM_LUNS; lun++) {
			struct ahd_tmode_lstate* lstate;

			lstate = tstate->enabled_luns[lun];
			if (lstate == NULL)
				continue;

			ahd_queue_lstate_event(ahd, lstate, CAM_TARGET_WILDCARD,
					       EVENT_TYPE_BUS_RESET, /*arg*/0);
			ahd_send_lstate_events(ahd, lstate);
		}
	}
#endif
	/* Notify the XPT that a bus reset occurred */
	ahd_send_async(ahd, devinfo.channel, CAM_TARGET_WILDCARD,
		       CAM_LUN_WILDCARD, AC_BUS_RESET, NULL);
	ahd_restart(ahd);
	/*
	 * Freeze the SIMQ until our poller can determine that
	 * the bus reset has really gone away.  We set the initial
	 * timer to 0 to have the check performed as soon as possible
	 * from the timer context.
	 */
	if ((ahd->flags & AHD_RESET_POLL_ACTIVE) == 0) {
		ahd->flags |= AHD_RESET_POLL_ACTIVE;
		aic_freeze_simq(ahd);
		aic_timer_reset(&ahd->reset_timer, 0, ahd_reset_poll, ahd);
	}
	return (found);
}