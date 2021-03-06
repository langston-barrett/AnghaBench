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
typedef  int u8 ;
struct iwl_fw {int phy_config; } ;

/* Variables and functions */
 int FW_PHY_CFG_RX_CHAIN ; 
 int FW_PHY_CFG_RX_CHAIN_POS ; 

__attribute__((used)) static inline u8 iwl_fw_valid_rx_ant(const struct iwl_fw *fw)
{
	return (fw->phy_config & FW_PHY_CFG_RX_CHAIN) >>
		FW_PHY_CFG_RX_CHAIN_POS;
}