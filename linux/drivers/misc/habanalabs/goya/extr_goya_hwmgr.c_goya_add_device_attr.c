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
struct hl_device {int dummy; } ;
struct attribute_group {int /*<<< orphan*/  attrs; } ;

/* Variables and functions */
 int /*<<< orphan*/  goya_dev_attrs ; 

void goya_add_device_attr(struct hl_device *hdev,
			struct attribute_group *dev_attr_grp)
{
	dev_attr_grp->attrs = goya_dev_attrs;
}