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
struct mvneta_port {int /*<<< orphan*/  phylink; } ;

/* Variables and functions */
 struct mvneta_port* netdev_priv (struct net_device*) ; 
 int phylink_ethtool_nway_reset (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mvneta_ethtool_nway_reset(struct net_device *dev)
{
	struct mvneta_port *pp = netdev_priv(dev);

	return phylink_ethtool_nway_reset(pp->phylink);
}