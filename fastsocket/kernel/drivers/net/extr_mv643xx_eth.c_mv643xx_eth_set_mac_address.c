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
struct sockaddr {int /*<<< orphan*/  sa_data; } ;
struct net_device {int /*<<< orphan*/  dev_addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  ETH_ALEN ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mv643xx_eth_program_unicast_filter (struct net_device*) ; 
 int /*<<< orphan*/  netif_addr_lock_bh (struct net_device*) ; 
 int /*<<< orphan*/  netif_addr_unlock_bh (struct net_device*) ; 

__attribute__((used)) static int mv643xx_eth_set_mac_address(struct net_device *dev, void *addr)
{
	struct sockaddr *sa = addr;

	memcpy(dev->dev_addr, sa->sa_data, ETH_ALEN);

	netif_addr_lock_bh(dev);
	mv643xx_eth_program_unicast_filter(dev);
	netif_addr_unlock_bh(dev);

	return 0;
}