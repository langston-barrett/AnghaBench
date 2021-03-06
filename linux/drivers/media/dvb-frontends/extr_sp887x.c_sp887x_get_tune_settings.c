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
struct dvb_frontend_tune_settings {int min_delay_ms; int step_size; int max_drift; } ;
struct dvb_frontend {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int sp887x_get_tune_settings(struct dvb_frontend* fe, struct dvb_frontend_tune_settings* fesettings)
{
	fesettings->min_delay_ms = 350;
	fesettings->step_size = 166666*2;
	fesettings->max_drift = (166666*2)+1;
	return 0;
}