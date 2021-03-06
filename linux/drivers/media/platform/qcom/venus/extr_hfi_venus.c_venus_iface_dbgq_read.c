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
struct venus_hfi_device {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int venus_iface_dbgq_read_nolock (struct venus_hfi_device*,void*) ; 

__attribute__((used)) static int venus_iface_dbgq_read(struct venus_hfi_device *hdev, void *pkt)
{
	int ret;

	if (!pkt)
		return -EINVAL;

	mutex_lock(&hdev->lock);
	ret = venus_iface_dbgq_read_nolock(hdev, pkt);
	mutex_unlock(&hdev->lock);

	return ret;
}