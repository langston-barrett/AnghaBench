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

/* Variables and functions */
 int /*<<< orphan*/  RCU ; 
 int /*<<< orphan*/  __acquire (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rcu_read_unlock () ; 

__attribute__((used)) static inline void ttm_base_object_noref_release(void)
{
	__acquire(RCU);
	rcu_read_unlock();
}