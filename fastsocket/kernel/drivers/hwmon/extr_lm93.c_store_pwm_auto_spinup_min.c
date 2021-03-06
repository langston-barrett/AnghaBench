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
typedef  int u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct lm93_data {int** block9; int /*<<< orphan*/  update_lock; } ;
struct i2c_client {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  size_t ssize_t ;
struct TYPE_2__ {int index; } ;

/* Variables and functions */
 size_t LM93_PWM_CTL3 ; 
 size_t LM93_PWM_CTL4 ; 
 int /*<<< orphan*/  LM93_PWM_MAP_HI_FREQ ; 
 int /*<<< orphan*/  LM93_PWM_MAP_LO_FREQ ; 
 int LM93_PWM_TO_REG (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LM93_REG_PWM_CTL (int,size_t) ; 
 struct lm93_data* i2c_get_clientdata (struct i2c_client*) ; 
 int lm93_read_byte (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lm93_write_byte (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  simple_strtoul (char const*,int /*<<< orphan*/ *,int) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 
 TYPE_1__* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static ssize_t store_pwm_auto_spinup_min(struct device *dev,
						struct device_attribute *attr,
						const char *buf, size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct i2c_client *client = to_i2c_client(dev);
	struct lm93_data *data = i2c_get_clientdata(client);
	u32 val = simple_strtoul(buf, NULL, 10);
	u8 ctl3, ctl4;

	mutex_lock(&data->update_lock);
	ctl3 = lm93_read_byte(client,LM93_REG_PWM_CTL(nr, LM93_PWM_CTL3));
	ctl4 = lm93_read_byte(client,LM93_REG_PWM_CTL(nr, LM93_PWM_CTL4));
	ctl3 = (ctl3 & 0xf0) | 	LM93_PWM_TO_REG(val, (ctl4 & 0x07) ?
			LM93_PWM_MAP_LO_FREQ :
			LM93_PWM_MAP_HI_FREQ);
	data->block9[nr][LM93_PWM_CTL3] = ctl3;
	lm93_write_byte(client,LM93_REG_PWM_CTL(nr, LM93_PWM_CTL3), ctl3);
	mutex_unlock(&data->update_lock);
	return count;
}