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
struct eap_sm {int MaxRetrans; } ;

/* Variables and functions */

__attribute__((used)) static int eap_wsc_getTimeout(struct eap_sm *sm, void *priv)
{
	/* Recommended retransmit times: retransmit timeout 5 seconds,
	 * per-message timeout 15 seconds, i.e., 3 tries. */
	sm->MaxRetrans = 2; /* total 3 attempts */
	return 5;
}