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
struct typhoon {int /*<<< orphan*/  wol_events; } ;
struct net_device {int dummy; } ;
struct ethtool_wolinfo {int wolopts; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  TYPHOON_WAKE_LINK_EVENT ; 
 int /*<<< orphan*/  TYPHOON_WAKE_MAGIC_PKT ; 
 int WAKE_MAGIC ; 
 int WAKE_PHY ; 
 struct typhoon* netdev_priv (struct net_device*) ; 

__attribute__((used)) static int
typhoon_set_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
	struct typhoon *tp = netdev_priv(dev);

	if(wol->wolopts & ~(WAKE_PHY | WAKE_MAGIC))
		return -EINVAL;

	tp->wol_events = 0;
	if(wol->wolopts & WAKE_PHY)
		tp->wol_events |= TYPHOON_WAKE_LINK_EVENT;
	if(wol->wolopts & WAKE_MAGIC)
		tp->wol_events |= TYPHOON_WAKE_MAGIC_PKT;

	return 0;
}