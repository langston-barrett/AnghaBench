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
struct dvb_frontend {int dummy; } ;

/* Variables and functions */
 int dib3000mb_set_frontend (struct dvb_frontend*,int) ; 

__attribute__((used)) static int dib3000mb_set_frontend_and_tuner(struct dvb_frontend *fe)
{
	return dib3000mb_set_frontend(fe, 1);
}