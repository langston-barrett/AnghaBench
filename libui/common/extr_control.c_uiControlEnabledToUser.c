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
typedef  int /*<<< orphan*/  uiControl ;

/* Variables and functions */
 int /*<<< orphan*/  uiControlEnabled (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * uiControlParent (int /*<<< orphan*/ *) ; 

int uiControlEnabledToUser(uiControl *c)
{
	while (c != NULL) {
		if (!uiControlEnabled(c))
			return 0;
		c = uiControlParent(c);
	}
	return 1;
}