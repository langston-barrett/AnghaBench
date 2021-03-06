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
struct etm_config {unsigned long ctxid_mask; } ;
struct etm_drvdata {struct etm_config config; } ;
struct device_attribute {int dummy; } ;
struct device {int /*<<< orphan*/  parent; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  current ; 
 struct etm_drvdata* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  init_pid_ns ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/ * task_active_pid_ns (int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t ctxid_mask_store(struct device *dev,
				struct device_attribute *attr,
				const char *buf, size_t size)
{
	int ret;
	unsigned long val;
	struct etm_drvdata *drvdata = dev_get_drvdata(dev->parent);
	struct etm_config *config = &drvdata->config;

	/*
	 * Don't use contextID tracing if coming from a PID namespace.  See
	 * comment in ctxid_pid_store().
	 */
	if (task_active_pid_ns(current) != &init_pid_ns)
		return -EINVAL;

	ret = kstrtoul(buf, 16, &val);
	if (ret)
		return ret;

	config->ctxid_mask = val;
	return size;
}