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
struct omap_hsmmc_host {int dma_ch; int /*<<< orphan*/  mmc; struct mmc_request* mrq; int /*<<< orphan*/  dma_len; scalar_t__ use_dma; int /*<<< orphan*/ * data; scalar_t__ response_busy; TYPE_1__* cmd; } ;
struct mmc_request {int dummy; } ;
struct mmc_data {int blocks; int blksz; int /*<<< orphan*/  stop; struct mmc_request* mrq; scalar_t__ bytes_xfered; int /*<<< orphan*/  error; int /*<<< orphan*/  sg; } ;
struct TYPE_2__ {int opcode; } ;

/* Variables and functions */
 int /*<<< orphan*/  dma_unmap_sg (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmc_dev (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmc_request_done (int /*<<< orphan*/ ,struct mmc_request*) ; 
 int /*<<< orphan*/  omap_hsmmc_get_dma_dir (struct omap_hsmmc_host*,struct mmc_data*) ; 
 int /*<<< orphan*/  omap_hsmmc_start_command (struct omap_hsmmc_host*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
omap_hsmmc_xfer_done(struct omap_hsmmc_host *host, struct mmc_data *data)
{
	if (!data) {
		struct mmc_request *mrq = host->mrq;

		/* TC before CC from CMD6 - don't know why, but it happens */
		if (host->cmd && host->cmd->opcode == 6 &&
		    host->response_busy) {
			host->response_busy = 0;
			return;
		}

		host->mrq = NULL;
		mmc_request_done(host->mmc, mrq);
		return;
	}

	host->data = NULL;

	if (host->use_dma && host->dma_ch != -1)
		dma_unmap_sg(mmc_dev(host->mmc), data->sg, host->dma_len,
			omap_hsmmc_get_dma_dir(host, data));

	if (!data->error)
		data->bytes_xfered += data->blocks * (data->blksz);
	else
		data->bytes_xfered = 0;

	if (!data->stop) {
		host->mrq = NULL;
		mmc_request_done(host->mmc, data->mrq);
		return;
	}
	omap_hsmmc_start_command(host, data->stop, NULL);
}