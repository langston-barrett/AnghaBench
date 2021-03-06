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
struct sensor_device_attribute {size_t index; } ;
struct menf21bmc_hwmon {int* in_val; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 scalar_t__ IS_ERR (struct menf21bmc_hwmon*) ; 
 int /*<<< orphan*/  PTR_ERR (struct menf21bmc_hwmon*) ; 
 struct menf21bmc_hwmon* menf21bmc_hwmon_update (struct device*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 struct sensor_device_attribute* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static ssize_t
in_show(struct device *dev, struct device_attribute *devattr, char *buf)
{
	struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
	struct menf21bmc_hwmon *drv_data = menf21bmc_hwmon_update(dev);

	if (IS_ERR(drv_data))
		return PTR_ERR(drv_data);

	return sprintf(buf, "%d\n", drv_data->in_val[attr->index]);
}