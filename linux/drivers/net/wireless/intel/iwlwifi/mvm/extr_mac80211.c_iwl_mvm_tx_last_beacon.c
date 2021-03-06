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
struct iwl_mvm {int ibss_manager; } ;
struct ieee80211_hw {int dummy; } ;

/* Variables and functions */
 struct iwl_mvm* IWL_MAC80211_GET_MVM (struct ieee80211_hw*) ; 

__attribute__((used)) static int iwl_mvm_tx_last_beacon(struct ieee80211_hw *hw)
{
	struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);

	return mvm->ibss_manager;
}