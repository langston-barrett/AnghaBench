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
struct mtd_blktrans_dev {int /*<<< orphan*/  ref; } ;
struct gendisk {struct mtd_blktrans_dev* private_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  blktrans_ref_mutex ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static struct mtd_blktrans_dev *blktrans_dev_get(struct gendisk *disk)
{
	struct mtd_blktrans_dev *dev;

	mutex_lock(&blktrans_ref_mutex);
	dev = disk->private_data;

	if (!dev)
		goto unlock;
	kref_get(&dev->ref);
unlock:
	mutex_unlock(&blktrans_ref_mutex);
	return dev;
}