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

/* Variables and functions */
 int IFLA_OFFLOAD_XSTATS_CPU_HIT ; 

__attribute__((used)) static bool port_has_offload_stats(const struct net_device *netdev,
				   int attr_id)
{
	return (attr_id == IFLA_OFFLOAD_XSTATS_CPU_HIT);
}