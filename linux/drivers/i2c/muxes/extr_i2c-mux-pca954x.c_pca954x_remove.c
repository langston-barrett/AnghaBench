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
struct i2c_mux_core {int dummy; } ;
struct i2c_client {int dummy; } ;

/* Variables and functions */
 struct i2c_mux_core* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  pca954x_cleanup (struct i2c_mux_core*) ; 

__attribute__((used)) static int pca954x_remove(struct i2c_client *client)
{
	struct i2c_mux_core *muxc = i2c_get_clientdata(client);

	pca954x_cleanup(muxc);
	return 0;
}