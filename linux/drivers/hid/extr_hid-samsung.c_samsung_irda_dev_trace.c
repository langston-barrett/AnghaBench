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
struct hid_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  hid_info (struct hid_device*,char*,unsigned int) ; 

__attribute__((used)) static inline void samsung_irda_dev_trace(struct hid_device *hdev,
		unsigned int rsize)
{
	hid_info(hdev, "fixing up Samsung IrDA %d byte report descriptor\n",
		 rsize);
}