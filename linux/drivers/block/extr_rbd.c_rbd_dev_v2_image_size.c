#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  image_size; int /*<<< orphan*/  obj_order; } ;
struct rbd_device {TYPE_1__ header; } ;

/* Variables and functions */
 int /*<<< orphan*/  CEPH_NOSNAP ; 
 int _rbd_dev_v2_snap_size (struct rbd_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int rbd_dev_v2_image_size(struct rbd_device *rbd_dev)
{
	return _rbd_dev_v2_snap_size(rbd_dev, CEPH_NOSNAP,
					&rbd_dev->header.obj_order,
					&rbd_dev->header.image_size);
}