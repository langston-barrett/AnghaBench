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
struct TYPE_2__ {int size; } ;
struct uvc_control {TYPE_1__ info; int /*<<< orphan*/ * uvc_data; } ;
typedef  int /*<<< orphan*/  __u8 ;

/* Variables and functions */

__attribute__((used)) static inline __u8 *uvc_ctrl_data(struct uvc_control *ctrl, int id)
{
	return ctrl->uvc_data + id * ctrl->info.size;
}