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
typedef  int /*<<< orphan*/  va_list ;

/* Variables and functions */
 int NS_UNAVAIL ; 
 int /*<<< orphan*/  SET_TERMINATOR (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  group ; 
 int stub1 () ; 

int
__nss_compat_endgrent(void *retval, void *mdata, va_list ap)
{

	SET_TERMINATOR(group, NULL);
	((int (*)(void))mdata)();
	return (NS_UNAVAIL);
}