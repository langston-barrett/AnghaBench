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

/* Variables and functions */
 int /*<<< orphan*/  sw_i2c_scl (int) ; 
 int /*<<< orphan*/  sw_i2c_sda (int) ; 

__attribute__((used)) static void sw_i2c_stop(void)
{
	/* Stop the I2C */
	sw_i2c_scl(1);
	sw_i2c_sda(0);
	sw_i2c_sda(1);
}