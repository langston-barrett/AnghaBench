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
struct i2c_client {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  i2c_get_clientdata (struct i2c_client*) ; 
 int ms5611_remove (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ms5611_i2c_remove(struct i2c_client *client)
{
	return ms5611_remove(i2c_get_clientdata(client));
}