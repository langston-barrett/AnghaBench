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
struct mpoa_client {int dev_num; struct mpoa_client* next; } ;

/* Variables and functions */
 struct mpoa_client* mpcs ; 

__attribute__((used)) static struct mpoa_client *find_mpc_by_itfnum(int itf)
{
	struct mpoa_client *mpc;

	mpc = mpcs;  /* our global linked list */
	while (mpc != NULL) {
		if (mpc->dev_num == itf)
			return mpc;
		mpc = mpc->next;
	}

	return NULL;   /* not found */
}