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
struct ifreq {int dummy; } ;

/* Variables and functions */
 int EOPNOTSUPP ; 

__attribute__((used)) static int mcs_net_ioctl(struct net_device *netdev, struct ifreq *rq, int cmd)
{
	/* struct if_irda_req *irq = (struct if_irda_req *)rq; */
	/* struct mcs_cb *mcs = netdev_priv(netdev); */
	int ret = 0;

	switch (cmd) {
	default:
		ret = -EOPNOTSUPP;
	}

	return ret;
}