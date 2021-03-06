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
struct ieee80211_dfs_state {int /*<<< orphan*/ * lastchan; int /*<<< orphan*/  nol_timer; } ;
struct ieee80211com {int ic_nchans; TYPE_1__* ic_channels; struct ieee80211_dfs_state ic_dfs; } ;
struct TYPE_2__ {scalar_t__ ic_state; } ;

/* Variables and functions */
 int /*<<< orphan*/  callout_drain (int /*<<< orphan*/ *) ; 

void
ieee80211_dfs_reset(struct ieee80211com *ic)
{
	struct ieee80211_dfs_state *dfs = &ic->ic_dfs;
	int i;

	/* NB: we assume no locking is needed */
	/* NB: cac_timer should be cleared by the state machine */
	callout_drain(&dfs->nol_timer);
	for (i = 0; i < ic->ic_nchans; i++)
		ic->ic_channels[i].ic_state = 0;
	dfs->lastchan = NULL;
}