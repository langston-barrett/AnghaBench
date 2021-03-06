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
struct net_device {int dummy; } ;
struct ethtool_cmd {scalar_t__ autoneg; scalar_t__ duplex; } ;

/* Variables and functions */
 scalar_t__ AUTONEG_ENABLE ; 
 scalar_t__ DUPLEX_FULL ; 
 int EOPNOTSUPP ; 
 scalar_t__ SPEED_10000 ; 
 scalar_t__ ethtool_cmd_speed (struct ethtool_cmd*) ; 

__attribute__((used)) static int
bnad_set_settings(struct net_device *netdev, struct ethtool_cmd *cmd)
{
	/* 10G full duplex setting supported only */
	if (cmd->autoneg == AUTONEG_ENABLE)
		return -EOPNOTSUPP; else {
		if ((ethtool_cmd_speed(cmd) == SPEED_10000)
		    && (cmd->duplex == DUPLEX_FULL))
			return 0;
	}

	return -EOPNOTSUPP;
}