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
 int /*<<< orphan*/  xmlFree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xmlRMutexLock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xmlRMutexUnlock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * xsltLocaleList ; 
 int /*<<< orphan*/  xsltLocaleMutex ; 

void
xsltFreeLocales(void) {
#ifdef XSLT_LOCALE_WINAPI
    xmlRMutexLock(xsltLocaleMutex);
    xmlFree(xsltLocaleList);
    xsltLocaleList = NULL;
    xmlRMutexUnlock(xsltLocaleMutex);
#endif
}