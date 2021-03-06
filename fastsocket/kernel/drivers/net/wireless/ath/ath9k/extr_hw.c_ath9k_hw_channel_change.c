#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  scalar_t__ u32 ;
struct TYPE_4__ {int hw_caps; } ;
struct ath_hw {int /*<<< orphan*/  ah_flags; TYPE_3__* eep_ops; TYPE_2__* curchan; TYPE_1__ caps; } ;
struct ath_common {int dummy; } ;
struct ath9k_channel {int channelFlags; scalar_t__ chanmode; } ;
struct TYPE_6__ {int /*<<< orphan*/  (* set_board_values ) (struct ath_hw*,struct ath9k_channel*) ;} ;
struct TYPE_5__ {int channelFlags; scalar_t__ chanmode; } ;

/* Variables and functions */
 int /*<<< orphan*/  AH_FASTCC ; 
 scalar_t__ AR_NUM_QCU ; 
 int ATH9K_HW_CAP_EDMA ; 
 int CHANNEL_2GHZ ; 
 int CHANNEL_5GHZ ; 
 scalar_t__ IS_CHAN_HT (struct ath9k_channel*) ; 
 scalar_t__ IS_CHAN_OFDM (struct ath9k_channel*) ; 
 int /*<<< orphan*/  QUEUE ; 
 int /*<<< orphan*/  ath9k_hw_apply_txpower (struct ath_hw*,struct ath9k_channel*,int) ; 
 struct ath_common* ath9k_hw_common (struct ath_hw*) ; 
 scalar_t__ ath9k_hw_fast_chan_change (struct ath_hw*,struct ath9k_channel*,scalar_t__*) ; 
 int /*<<< orphan*/  ath9k_hw_init_bb (struct ath_hw*,struct ath9k_channel*) ; 
 int /*<<< orphan*/  ath9k_hw_init_cal (struct ath_hw*,struct ath9k_channel*) ; 
 int /*<<< orphan*/  ath9k_hw_init_pll (struct ath_hw*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ath9k_hw_mark_phy_inactive (struct ath_hw*) ; 
 scalar_t__ ath9k_hw_numtxpending (struct ath_hw*,scalar_t__) ; 
 int ath9k_hw_rf_set_freq (struct ath_hw*,struct ath9k_channel*) ; 
 int /*<<< orphan*/  ath9k_hw_rfbus_done (struct ath_hw*) ; 
 int /*<<< orphan*/  ath9k_hw_rfbus_req (struct ath_hw*) ; 
 int /*<<< orphan*/  ath9k_hw_set_channel_regs (struct ath_hw*,struct ath9k_channel*) ; 
 int /*<<< orphan*/  ath9k_hw_set_clockrate (struct ath_hw*) ; 
 int /*<<< orphan*/  ath9k_hw_set_delta_slope (struct ath_hw*,struct ath9k_channel*) ; 
 int /*<<< orphan*/  ath9k_hw_spur_mitigate_freq (struct ath_hw*,struct ath9k_channel*) ; 
 int /*<<< orphan*/  ath_dbg (struct ath_common*,int /*<<< orphan*/ ,char*,scalar_t__) ; 
 int /*<<< orphan*/  ath_err (struct ath_common*,char*) ; 
 int /*<<< orphan*/  stub1 (struct ath_hw*,struct ath9k_channel*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static bool ath9k_hw_channel_change(struct ath_hw *ah,
				    struct ath9k_channel *chan)
{
	struct ath_common *common = ath9k_hw_common(ah);
	u32 qnum;
	int r;
	bool edma = !!(ah->caps.hw_caps & ATH9K_HW_CAP_EDMA);
	bool band_switch, mode_diff;
	u8 ini_reloaded;

	band_switch = (chan->channelFlags & (CHANNEL_2GHZ | CHANNEL_5GHZ)) !=
		      (ah->curchan->channelFlags & (CHANNEL_2GHZ |
						    CHANNEL_5GHZ));
	mode_diff = (chan->chanmode != ah->curchan->chanmode);

	for (qnum = 0; qnum < AR_NUM_QCU; qnum++) {
		if (ath9k_hw_numtxpending(ah, qnum)) {
			ath_dbg(common, QUEUE,
				"Transmit frames pending on queue %d\n", qnum);
			return false;
		}
	}

	if (!ath9k_hw_rfbus_req(ah)) {
		ath_err(common, "Could not kill baseband RX\n");
		return false;
	}

	if (edma && (band_switch || mode_diff)) {
		ath9k_hw_mark_phy_inactive(ah);
		udelay(5);

		ath9k_hw_init_pll(ah, NULL);

		if (ath9k_hw_fast_chan_change(ah, chan, &ini_reloaded)) {
			ath_err(common, "Failed to do fast channel change\n");
			return false;
		}
	}

	ath9k_hw_set_channel_regs(ah, chan);

	r = ath9k_hw_rf_set_freq(ah, chan);
	if (r) {
		ath_err(common, "Failed to set channel\n");
		return false;
	}
	ath9k_hw_set_clockrate(ah);
	ath9k_hw_apply_txpower(ah, chan, false);
	ath9k_hw_rfbus_done(ah);

	if (IS_CHAN_OFDM(chan) || IS_CHAN_HT(chan))
		ath9k_hw_set_delta_slope(ah, chan);

	ath9k_hw_spur_mitigate_freq(ah, chan);

	if (edma && (band_switch || mode_diff)) {
		ah->ah_flags |= AH_FASTCC;
		if (band_switch || ini_reloaded)
			ah->eep_ops->set_board_values(ah, chan);

		ath9k_hw_init_bb(ah, chan);

		if (band_switch || ini_reloaded)
			ath9k_hw_init_cal(ah, chan);
		ah->ah_flags &= ~AH_FASTCC;
	}

	return true;
}