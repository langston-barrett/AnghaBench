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
typedef  int /*<<< orphan*/  u8 ;
struct ib_device {int (* set_vf_link_state ) (struct ib_device*,int,int /*<<< orphan*/ ,int) ;} ;

/* Variables and functions */
 int ENOSYS ; 
 int stub1 (struct ib_device*,int,int /*<<< orphan*/ ,int) ; 

int ib_set_vf_link_state(struct ib_device *device, int vf, u8 port,
			 int state)
{
	if (!device->set_vf_link_state)
		return -ENOSYS;

	return device->set_vf_link_state(device, vf, port, state);
}