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
struct i2c_msg {int flags; scalar_t__ len; } ;
struct ec_response_i2c_passthru {int dummy; } ;

/* Variables and functions */
 int I2C_M_RD ; 

__attribute__((used)) static int ec_i2c_count_response(struct i2c_msg i2c_msgs[], int num)
{
	int size;
	int i;

	size = sizeof(struct ec_response_i2c_passthru);
	for (i = 0; i < num; i++)
		if (i2c_msgs[i].flags & I2C_M_RD)
			size += i2c_msgs[i].len;

	return size;
}