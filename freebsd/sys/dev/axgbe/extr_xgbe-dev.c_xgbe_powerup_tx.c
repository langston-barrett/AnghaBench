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
struct xgbe_prv_data {unsigned int channel_count; struct xgbe_channel* channel; } ;
struct xgbe_channel {int /*<<< orphan*/  tx_ring; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMA_CH_TCR ; 
 int /*<<< orphan*/  MAC_TCR ; 
 int /*<<< orphan*/  ST ; 
 int /*<<< orphan*/  TE ; 
 int /*<<< orphan*/  XGMAC_DMA_IOWRITE_BITS (struct xgbe_channel*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  XGMAC_IOWRITE_BITS (struct xgbe_prv_data*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void xgbe_powerup_tx(struct xgbe_prv_data *pdata)
{
	struct xgbe_channel *channel;
	unsigned int i;

	/* Enable each Tx DMA channel */
	channel = pdata->channel;
	for (i = 0; i < pdata->channel_count; i++, channel++) {
		if (!channel->tx_ring)
			break;

		XGMAC_DMA_IOWRITE_BITS(channel, DMA_CH_TCR, ST, 1);
	}

	/* Enable MAC Tx */
	XGMAC_IOWRITE_BITS(pdata, MAC_TCR, TE, 1);
}