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
typedef  scalar_t__ uint8_t ;
struct bxe_softc {int /*<<< orphan*/  ifp; } ;
struct bxe_fastpath {int /*<<< orphan*/  fp_hc_idx; int /*<<< orphan*/  igu_sb_id; int /*<<< orphan*/  tq_task; int /*<<< orphan*/  tq; int /*<<< orphan*/  index; struct bxe_softc* sc; } ;

/* Variables and functions */
 int /*<<< orphan*/  BLOGD (struct bxe_softc*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BXE_FP_TX_LOCK (struct bxe_fastpath*) ; 
 int /*<<< orphan*/  BXE_FP_TX_UNLOCK (struct bxe_fastpath*) ; 
 int /*<<< orphan*/  DBG_INTR ; 
 scalar_t__ FALSE ; 
 int IFF_DRV_RUNNING ; 
 int /*<<< orphan*/  IGU_INT_ENABLE ; 
 int /*<<< orphan*/  USTORM_ID ; 
 int /*<<< orphan*/  bxe_ack_sb (struct bxe_softc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 scalar_t__ bxe_has_rx_work (struct bxe_fastpath*) ; 
 scalar_t__ bxe_has_tx_work (struct bxe_fastpath*) ; 
 scalar_t__ bxe_rxeof (struct bxe_softc*,struct bxe_fastpath*) ; 
 scalar_t__ bxe_txeof (struct bxe_softc*,struct bxe_fastpath*) ; 
 int /*<<< orphan*/  bxe_update_fp_sb_idx (struct bxe_fastpath*) ; 
 int if_getdrvflags (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  le16toh (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  taskqueue_enqueue (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
bxe_handle_fp_tq(void *context,
                 int  pending)
{
    struct bxe_fastpath *fp = (struct bxe_fastpath *)context;
    struct bxe_softc *sc = fp->sc;
    uint8_t more_tx = FALSE;
    uint8_t more_rx = FALSE;

    BLOGD(sc, DBG_INTR, "---> FP TASK QUEUE (%d) <---\n", fp->index);

    /* XXX
     * IFF_DRV_RUNNING state can't be checked here since we process
     * slowpath events on a client queue during setup. Instead
     * we need to add a "process/continue" flag here that the driver
     * can use to tell the task here not to do anything.
     */
#if 0
    if (!(if_getdrvflags(sc->ifp) & IFF_DRV_RUNNING)) {
        return;
    }
#endif

    /* update the fastpath index */
    bxe_update_fp_sb_idx(fp);

    /* XXX add loop here if ever support multiple tx CoS */
    /* fp->txdata[cos] */
    if (bxe_has_tx_work(fp)) {
        BXE_FP_TX_LOCK(fp);
        more_tx = bxe_txeof(sc, fp);
        BXE_FP_TX_UNLOCK(fp);
    }

    if (bxe_has_rx_work(fp)) {
        more_rx = bxe_rxeof(sc, fp);
    }

    if (more_rx /*|| more_tx*/) {
        /* still more work to do */
        taskqueue_enqueue(fp->tq, &fp->tq_task);
        return;
    }

    bxe_ack_sb(sc, fp->igu_sb_id, USTORM_ID,
               le16toh(fp->fp_hc_idx), IGU_INT_ENABLE, 1);
}