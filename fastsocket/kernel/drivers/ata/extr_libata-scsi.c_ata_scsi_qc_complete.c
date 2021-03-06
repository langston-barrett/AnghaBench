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
typedef  int u8 ;
struct scsi_cmnd {int* cmnd; int /*<<< orphan*/  result; } ;
struct ata_queued_cmd {scalar_t__ err_mask; int /*<<< orphan*/  (* scsidone ) (struct scsi_cmnd*) ;int /*<<< orphan*/  result_tf; struct scsi_cmnd* scsicmd; struct ata_port* ap; } ;
struct ata_port {int /*<<< orphan*/  print_id; TYPE_1__* ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  error_handler; } ;

/* Variables and functions */
 int ATA_12 ; 
 int ATA_16 ; 
 int /*<<< orphan*/  SAM_STAT_GOOD ; 
 int /*<<< orphan*/  ata_dump_status (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ata_gen_ata_sense (struct ata_queued_cmd*) ; 
 int /*<<< orphan*/  ata_gen_passthru_sense (struct ata_queued_cmd*) ; 
 int /*<<< orphan*/  ata_qc_free (struct ata_queued_cmd*) ; 
 int /*<<< orphan*/  stub1 (struct scsi_cmnd*) ; 

__attribute__((used)) static void ata_scsi_qc_complete(struct ata_queued_cmd *qc)
{
	struct ata_port *ap = qc->ap;
	struct scsi_cmnd *cmd = qc->scsicmd;
	u8 *cdb = cmd->cmnd;
	int need_sense = (qc->err_mask != 0);

	/* For ATA pass thru (SAT) commands, generate a sense block if
	 * user mandated it or if there's an error.  Note that if we
	 * generate because the user forced us to, a check condition
	 * is generated and the ATA register values are returned
	 * whether the command completed successfully or not. If there
	 * was no error, SK, ASC and ASCQ will all be zero.
	 */
	if (((cdb[0] == ATA_16) || (cdb[0] == ATA_12)) &&
	    ((cdb[2] & 0x20) || need_sense)) {
		ata_gen_passthru_sense(qc);
	} else {
		if (!need_sense) {
			cmd->result = SAM_STAT_GOOD;
		} else {
			/* TODO: decide which descriptor format to use
			 * for 48b LBA devices and call that here
			 * instead of the fixed desc, which is only
			 * good for smaller LBA (and maybe CHS?)
			 * devices.
			 */
			ata_gen_ata_sense(qc);
		}
	}

	if (need_sense && !ap->ops->error_handler)
		ata_dump_status(ap->print_id, &qc->result_tf);

	qc->scsidone(cmd);

	ata_qc_free(qc);
}