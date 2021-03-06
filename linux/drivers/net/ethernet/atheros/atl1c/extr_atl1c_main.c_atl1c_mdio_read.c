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
typedef  int u16 ;
struct net_device {int dummy; } ;
struct atl1c_adapter {int /*<<< orphan*/  hw; } ;

/* Variables and functions */
 int /*<<< orphan*/  atl1c_read_phy_reg (int /*<<< orphan*/ *,int,int*) ; 
 struct atl1c_adapter* netdev_priv (struct net_device*) ; 

__attribute__((used)) static int atl1c_mdio_read(struct net_device *netdev, int phy_id, int reg_num)
{
	struct atl1c_adapter *adapter = netdev_priv(netdev);
	u16 result;

	atl1c_read_phy_reg(&adapter->hw, reg_num, &result);
	return result;
}