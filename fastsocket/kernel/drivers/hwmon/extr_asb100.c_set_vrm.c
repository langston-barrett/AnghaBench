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
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct asb100_data {int /*<<< orphan*/  vrm; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 struct asb100_data* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  simple_strtoul (char const*,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static ssize_t set_vrm(struct device *dev, struct device_attribute *attr,
		const char *buf, size_t count)
{
	struct asb100_data *data = dev_get_drvdata(dev);
	data->vrm = simple_strtoul(buf, NULL, 10);
	return count;
}