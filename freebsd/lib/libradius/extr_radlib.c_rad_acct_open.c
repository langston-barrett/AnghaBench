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
struct rad_handle {int /*<<< orphan*/  type; } ;

/* Variables and functions */
 int /*<<< orphan*/  RADIUS_ACCT ; 
 struct rad_handle* rad_open () ; 

struct rad_handle *
rad_acct_open(void)
{
	struct rad_handle *h;

	h = rad_open();
	if (h != NULL)
	        h->type = RADIUS_ACCT;
	return h;
}