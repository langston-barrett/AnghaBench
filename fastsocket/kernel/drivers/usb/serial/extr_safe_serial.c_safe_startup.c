#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct usb_serial {TYPE_3__* interface; } ;
struct TYPE_6__ {TYPE_2__* cur_altsetting; } ;
struct TYPE_4__ {int bInterfaceProtocol; } ;
struct TYPE_5__ {TYPE_1__ desc; } ;

/* Variables and functions */
 int EINVAL ; 
#define  LINEO_SAFESERIAL_CRC 129 
#define  LINEO_SAFESERIAL_CRC_PADDED 128 
 int padded ; 

__attribute__((used)) static int safe_startup(struct usb_serial *serial)
{
	switch (serial->interface->cur_altsetting->desc.bInterfaceProtocol) {
	case LINEO_SAFESERIAL_CRC:
		break;
	case LINEO_SAFESERIAL_CRC_PADDED:
		padded = 1;
		break;
	default:
		return -EINVAL;
	}
	return 0;
}