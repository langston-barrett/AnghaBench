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
typedef  int /*<<< orphan*/  u16 ;
struct dvb_usb_device {int /*<<< orphan*/  usb_mutex; } ;

/* Variables and functions */
 int dvb_usb_v2_generic_io (struct dvb_usb_device*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

int dvb_usbv2_generic_write(struct dvb_usb_device *d, u8 *buf, u16 len)
{
	int ret;

	mutex_lock(&d->usb_mutex);
	ret = dvb_usb_v2_generic_io(d, buf, len, NULL, 0);
	mutex_unlock(&d->usb_mutex);

	return ret;
}