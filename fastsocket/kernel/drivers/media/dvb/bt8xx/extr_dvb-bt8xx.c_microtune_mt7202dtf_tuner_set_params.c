#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct i2c_msg {int addr; int* buf; int len; int /*<<< orphan*/  flags; } ;
struct dvb_frontend_parameters {int frequency; } ;
struct TYPE_4__ {int /*<<< orphan*/  (* i2c_gate_ctrl ) (struct dvb_frontend*,int) ;} ;
struct dvb_frontend {TYPE_2__ ops; TYPE_1__* dvb; } ;
struct dvb_bt8xx_card {int /*<<< orphan*/  i2c_adapter; } ;
typedef  int /*<<< orphan*/  data ;
struct TYPE_3__ {scalar_t__ priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  i2c_transfer (int /*<<< orphan*/ ,struct i2c_msg*,int) ; 
 int /*<<< orphan*/  stub1 (struct dvb_frontend*,int) ; 

__attribute__((used)) static int microtune_mt7202dtf_tuner_set_params(struct dvb_frontend* fe, struct dvb_frontend_parameters* params)
{
	struct dvb_bt8xx_card *card = (struct dvb_bt8xx_card *) fe->dvb->priv;
	u8 cfg, cpump, band_select;
	u8 data[4];
	u32 div;
	struct i2c_msg msg = { .addr = 0x60, .flags = 0, .buf = data, .len = sizeof(data) };

	div = (36000000 + params->frequency + 83333) / 166666;
	cfg = 0x88;

	if (params->frequency < 175000000)
		cpump = 2;
	else if (params->frequency < 390000000)
		cpump = 1;
	else if (params->frequency < 470000000)
		cpump = 2;
	else if (params->frequency < 750000000)
		cpump = 2;
	else
		cpump = 3;

	if (params->frequency < 175000000)
		band_select = 0x0e;
	else if (params->frequency < 470000000)
		band_select = 0x05;
	else
		band_select = 0x03;

	data[0] = (div >> 8) & 0x7f;
	data[1] = div & 0xff;
	data[2] = ((div >> 10) & 0x60) | cfg;
	data[3] = (cpump << 6) | band_select;

	if (fe->ops.i2c_gate_ctrl)
		fe->ops.i2c_gate_ctrl(fe, 1);
	i2c_transfer(card->i2c_adapter, &msg, 1);
	return (div * 166666 - 36000000);
}