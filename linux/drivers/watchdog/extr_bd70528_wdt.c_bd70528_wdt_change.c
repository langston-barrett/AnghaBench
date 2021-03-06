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
struct wdtbd70528 {int /*<<< orphan*/  mfd; } ;

/* Variables and functions */
 int /*<<< orphan*/  bd70528_wdt_lock (int /*<<< orphan*/ ) ; 
 int bd70528_wdt_set_locked (struct wdtbd70528*,int) ; 
 int /*<<< orphan*/  bd70528_wdt_unlock (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int bd70528_wdt_change(struct wdtbd70528 *w, int enable)
{
	int ret;

	bd70528_wdt_lock(w->mfd);
	ret = bd70528_wdt_set_locked(w, enable);
	bd70528_wdt_unlock(w->mfd);

	return ret;
}