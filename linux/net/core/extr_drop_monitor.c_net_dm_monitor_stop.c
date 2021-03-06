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
struct netlink_ext_ack {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  TRACE_OFF ; 
 int /*<<< orphan*/  net_dm_hw_monitor_stop (struct netlink_ext_ack*) ; 
 int /*<<< orphan*/  set_all_monitor_traces (int /*<<< orphan*/ ,struct netlink_ext_ack*) ; 

__attribute__((used)) static void net_dm_monitor_stop(bool set_sw, bool set_hw,
				struct netlink_ext_ack *extack)
{
	if (set_hw)
		net_dm_hw_monitor_stop(extack);
	if (set_sw)
		set_all_monitor_traces(TRACE_OFF, extack);
}