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
struct nitrox_device {int /*<<< orphan*/  list; } ;

/* Variables and functions */
 int /*<<< orphan*/  devlist_lock ; 
 int /*<<< orphan*/  list_del (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  num_devices ; 

__attribute__((used)) static void nitrox_remove_from_devlist(struct nitrox_device *ndev)
{
	mutex_lock(&devlist_lock);
	list_del(&ndev->list);
	num_devices--;
	mutex_unlock(&devlist_lock);
}