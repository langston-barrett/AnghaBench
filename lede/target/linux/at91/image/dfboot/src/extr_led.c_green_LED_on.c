#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int PIO_CODR; } ;
typedef  TYPE_1__* AT91PS_PIO ;

/* Variables and functions */
 TYPE_1__* AT91C_BASE_PIOB ; 

void	green_LED_on(void)
{
	AT91PS_PIO	PIOB	= AT91C_BASE_PIOB;
//	PIOB->PIO_CODR		= GREEN_LED;
	PIOB->PIO_CODR		= (1 << 0);
}