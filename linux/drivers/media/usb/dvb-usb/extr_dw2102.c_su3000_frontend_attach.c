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
struct dw2102_state {int* data; } ;
struct dvb_usb_device {int /*<<< orphan*/  i2c_adap; int /*<<< orphan*/  data_mutex; struct dw2102_state* priv; } ;
struct dvb_usb_adapter {TYPE_1__* fe_adap; struct dvb_usb_device* dev; } ;
struct TYPE_2__ {int /*<<< orphan*/ * fe; } ;

/* Variables and functions */
 int EIO ; 
 int /*<<< orphan*/  ds3000_attach ; 
 int /*<<< orphan*/ * dvb_attach (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,...) ; 
 scalar_t__ dvb_usb_generic_rw (struct dvb_usb_device*,int*,int,int*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dw2104_ts2020_config ; 
 int /*<<< orphan*/  err (char*) ; 
 int /*<<< orphan*/  info (char*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  su3000_ds3000_config ; 
 int /*<<< orphan*/  ts2020_attach ; 

__attribute__((used)) static int su3000_frontend_attach(struct dvb_usb_adapter *adap)
{
	struct dvb_usb_device *d = adap->dev;
	struct dw2102_state *state = d->priv;

	mutex_lock(&d->data_mutex);

	state->data[0] = 0xe;
	state->data[1] = 0x80;
	state->data[2] = 0;

	if (dvb_usb_generic_rw(d, state->data, 3, state->data, 1, 0) < 0)
		err("command 0x0e transfer failed.");

	state->data[0] = 0xe;
	state->data[1] = 0x02;
	state->data[2] = 1;

	if (dvb_usb_generic_rw(d, state->data, 3, state->data, 1, 0) < 0)
		err("command 0x0e transfer failed.");
	msleep(300);

	state->data[0] = 0xe;
	state->data[1] = 0x83;
	state->data[2] = 0;

	if (dvb_usb_generic_rw(d, state->data, 3, state->data, 1, 0) < 0)
		err("command 0x0e transfer failed.");

	state->data[0] = 0xe;
	state->data[1] = 0x83;
	state->data[2] = 1;

	if (dvb_usb_generic_rw(d, state->data, 3, state->data, 1, 0) < 0)
		err("command 0x0e transfer failed.");

	state->data[0] = 0x51;

	if (dvb_usb_generic_rw(d, state->data, 1, state->data, 1, 0) < 0)
		err("command 0x51 transfer failed.");

	mutex_unlock(&d->data_mutex);

	adap->fe_adap[0].fe = dvb_attach(ds3000_attach, &su3000_ds3000_config,
					&d->i2c_adap);
	if (adap->fe_adap[0].fe == NULL)
		return -EIO;

	if (dvb_attach(ts2020_attach, adap->fe_adap[0].fe,
				&dw2104_ts2020_config,
				&d->i2c_adap)) {
		info("Attached DS3000/TS2020!");
		return 0;
	}

	info("Failed to attach DS3000/TS2020!");
	return -EIO;
}