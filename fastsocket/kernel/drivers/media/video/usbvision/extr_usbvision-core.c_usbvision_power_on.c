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
struct usb_usbvision {int power; } ;

/* Variables and functions */
 int /*<<< orphan*/  DBG_FUNC ; 
 int /*<<< orphan*/  PDEBUG (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  USBVISION_PWR_REG ; 
 int USBVISION_PWR_VID ; 
 int USBVISION_RES2 ; 
 int USBVISION_SSPND_EN ; 
 int usbvision_write_reg (struct usb_usbvision*,int /*<<< orphan*/ ,int) ; 

int usbvision_power_on(struct usb_usbvision *usbvision)
{
	int err_code = 0;

	PDEBUG(DBG_FUNC, "");

	usbvision_write_reg(usbvision, USBVISION_PWR_REG, USBVISION_SSPND_EN);
	usbvision_write_reg(usbvision, USBVISION_PWR_REG,
			USBVISION_SSPND_EN | USBVISION_RES2);

	usbvision_write_reg(usbvision, USBVISION_PWR_REG,
			USBVISION_SSPND_EN | USBVISION_PWR_VID);
	err_code = usbvision_write_reg(usbvision, USBVISION_PWR_REG,
			USBVISION_SSPND_EN | USBVISION_PWR_VID | USBVISION_RES2);
	if (err_code == 1)
		usbvision->power = 1;
	PDEBUG(DBG_FUNC, "%s: err_code %d", (err_code < 0) ? "ERROR" : "power is on", err_code);
	return err_code;
}