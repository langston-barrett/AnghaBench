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
struct wait_bit_key {int dummy; } ;

/* Variables and functions */
 int ERESTARTSYS ; 
 int /*<<< orphan*/  current ; 
 int /*<<< orphan*/  freezable_schedule_unsafe () ; 
 scalar_t__ signal_pending_state (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
cifs_wait_bit_killable(struct wait_bit_key *key, int mode)
{
	freezable_schedule_unsafe();
	if (signal_pending_state(mode, current))
		return -ERESTARTSYS;
	return 0;
}