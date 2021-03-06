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
struct bufferevent_private {int dummy; } ;
typedef  int /*<<< orphan*/  ev_ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  bufferevent_get_rlim_max_ (struct bufferevent_private*,int) ; 

ev_ssize_t
bufferevent_get_write_max_(struct bufferevent_private *bev)
{
	return bufferevent_get_rlim_max_(bev, 1);
}