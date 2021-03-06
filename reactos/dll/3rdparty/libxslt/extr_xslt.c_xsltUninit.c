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
 scalar_t__ initialized ; 
 int /*<<< orphan*/  xmlFreeRMutex (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * xsltLocaleMutex ; 

void
xsltUninit (void) {
#ifdef XSLT_LOCALE_WINAPI
    xmlFreeRMutex(xsltLocaleMutex);
    xsltLocaleMutex = NULL;
#endif
    initialized = 0;
}