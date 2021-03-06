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
typedef  int /*<<< orphan*/  tsdn_t ;

/* Variables and functions */
 int /*<<< orphan*/  malloc_mutex_lock (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  malloc_mutex_unlock (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int prof_active ; 
 int /*<<< orphan*/  prof_active_assert () ; 
 int /*<<< orphan*/  prof_active_mtx ; 

bool
prof_active_get(tsdn_t *tsdn) {
	bool prof_active_current;

	prof_active_assert();
	malloc_mutex_lock(tsdn, &prof_active_mtx);
	prof_active_current = prof_active;
	malloc_mutex_unlock(tsdn, &prof_active_mtx);
	return prof_active_current;
}