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
struct wlp_wss {int /*<<< orphan*/  mutex; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  PAGE_SIZE ; 
 int __wlp_wss_properties_show (struct wlp_wss*,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ mutex_lock_interruptible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static ssize_t wlp_wss_properties_show(struct wlp_wss *wss, char *buf)
{
	int result = 0;

	if (mutex_lock_interruptible(&wss->mutex))
		goto out;
	result = __wlp_wss_properties_show(wss, buf, PAGE_SIZE);
	mutex_unlock(&wss->mutex);
out:
	return result;
}