#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct i2c_adapter {int dummy; } ;
struct dvb_usb_adapter {TYPE_4__* fe_adap; struct dib0700_adapter_state* priv; } ;
struct TYPE_10__ {int /*<<< orphan*/  (* set_gpio ) (TYPE_5__*,int,int /*<<< orphan*/ ,int) ;int /*<<< orphan*/  get_adc_power; int /*<<< orphan*/  tuner_sleep; struct i2c_adapter* (* get_i2c_tuner ) (TYPE_5__*) ;} ;
struct dib0700_adapter_state {int /*<<< orphan*/  set_param_save; TYPE_1__ dib7000p_ops; } ;
struct TYPE_15__ {int /*<<< orphan*/  get_adc_power; int /*<<< orphan*/  sleep; int /*<<< orphan*/  reset; } ;
struct TYPE_11__ {int /*<<< orphan*/  set_params; } ;
struct TYPE_12__ {TYPE_2__ tuner_ops; } ;
struct TYPE_14__ {TYPE_3__ ops; } ;
struct TYPE_13__ {TYPE_5__* fe; } ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  dib0090_register ; 
 int /*<<< orphan*/  dib7090_agc_startup ; 
 int /*<<< orphan*/ * dvb_attach (int /*<<< orphan*/ ,TYPE_5__*,struct i2c_adapter*,TYPE_7__*) ; 
 TYPE_7__ nim7090_dib0090_config ; 
 struct i2c_adapter* stub1 (TYPE_5__*) ; 
 int /*<<< orphan*/  stub2 (TYPE_5__*,int,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int nim7090_tuner_attach(struct dvb_usb_adapter *adap)
{
	struct dib0700_adapter_state *st = adap->priv;
	struct i2c_adapter *tun_i2c = st->dib7000p_ops.get_i2c_tuner(adap->fe_adap[0].fe);

	nim7090_dib0090_config.reset = st->dib7000p_ops.tuner_sleep,
	nim7090_dib0090_config.sleep = st->dib7000p_ops.tuner_sleep,
	nim7090_dib0090_config.get_adc_power = st->dib7000p_ops.get_adc_power;

	if (dvb_attach(dib0090_register, adap->fe_adap[0].fe, tun_i2c, &nim7090_dib0090_config) == NULL)
		return -ENODEV;

	st->dib7000p_ops.set_gpio(adap->fe_adap[0].fe, 8, 0, 1);

	st->set_param_save = adap->fe_adap[0].fe->ops.tuner_ops.set_params;
	adap->fe_adap[0].fe->ops.tuner_ops.set_params = dib7090_agc_startup;
	return 0;
}