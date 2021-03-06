#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
struct lpfc_hba {int /*<<< orphan*/  mbox_mem_pool; int /*<<< orphan*/  ct_ev_lock; } ;
struct TYPE_9__ {int /*<<< orphan*/  sg_cnt; int /*<<< orphan*/  sg_list; int /*<<< orphan*/  payload_len; } ;
struct fc_bsg_job {int /*<<< orphan*/  (* job_done ) (struct fc_bsg_job*) ;TYPE_5__* reply; TYPE_2__ reply_payload; int /*<<< orphan*/ * dd_data; } ;
struct TYPE_10__ {int /*<<< orphan*/  dmabuffers; int /*<<< orphan*/  pmboxq; scalar_t__ mb; } ;
struct TYPE_11__ {TYPE_3__ mbox; } ;
struct bsg_job_data {TYPE_4__ context_un; struct fc_bsg_job* set_job; } ;
struct TYPE_8__ {int /*<<< orphan*/  mb; } ;
struct TYPE_13__ {TYPE_1__ u; struct bsg_job_data* context1; } ;
struct TYPE_12__ {scalar_t__ result; int /*<<< orphan*/  reply_payload_rcv_len; } ;
typedef  int /*<<< orphan*/  MAILBOX_t ;
typedef  TYPE_6__ LPFC_MBOXQ_t ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct bsg_job_data*) ; 
 int /*<<< orphan*/  lpfc_bsg_dma_page_free (struct lpfc_hba*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  mempool_free (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sg_copy_from_buffer (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  stub1 (struct fc_bsg_job*) ; 

void
lpfc_bsg_issue_mbox_cmpl(struct lpfc_hba *phba, LPFC_MBOXQ_t *pmboxq)
{
	struct bsg_job_data *dd_data;
	struct fc_bsg_job *job;
	uint32_t size;
	unsigned long flags;
	uint8_t *pmb, *pmb_buf;

	dd_data = pmboxq->context1;

	/*
	 * The outgoing buffer is readily referred from the dma buffer,
	 * just need to get header part from mailboxq structure.
	 */
	pmb = (uint8_t *)&pmboxq->u.mb;
	pmb_buf = (uint8_t *)dd_data->context_un.mbox.mb;
	memcpy(pmb_buf, pmb, sizeof(MAILBOX_t));

	/* Determine if job has been aborted */

	spin_lock_irqsave(&phba->ct_ev_lock, flags);
	job = dd_data->set_job;
	if (job) {
		/* Prevent timeout handling from trying to abort job  */
		job->dd_data = NULL;
	}
	spin_unlock_irqrestore(&phba->ct_ev_lock, flags);

	/* Copy the mailbox data to the job if it is still active */

	if (job) {
		size = job->reply_payload.payload_len;
		job->reply->reply_payload_rcv_len =
			sg_copy_from_buffer(job->reply_payload.sg_list,
					    job->reply_payload.sg_cnt,
					    pmb_buf, size);
	}

	dd_data->set_job = NULL;
	mempool_free(dd_data->context_un.mbox.pmboxq, phba->mbox_mem_pool);
	lpfc_bsg_dma_page_free(phba, dd_data->context_un.mbox.dmabuffers);
	kfree(dd_data);

	/* Complete the job if the job is still active */

	if (job) {
		job->reply->result = 0;
		job->job_done(job);
	}
	return;
}