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
struct rcu_segcblist {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  RCU_DONE_TAIL ; 
 scalar_t__ rcu_segcblist_is_enabled (struct rcu_segcblist*) ; 
 int /*<<< orphan*/  rcu_segcblist_restempty (struct rcu_segcblist*,int /*<<< orphan*/ ) ; 

bool rcu_segcblist_pend_cbs(struct rcu_segcblist *rsclp)
{
	return rcu_segcblist_is_enabled(rsclp) &&
	       !rcu_segcblist_restempty(rsclp, RCU_DONE_TAIL);
}