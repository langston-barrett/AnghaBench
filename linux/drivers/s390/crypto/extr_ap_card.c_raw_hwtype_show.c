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
struct ap_card {int raw_hwtype; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  snprintf (char*,int /*<<< orphan*/ ,char*,int) ; 
 struct ap_card* to_ap_card (struct device*) ; 

__attribute__((used)) static ssize_t raw_hwtype_show(struct device *dev,
			       struct device_attribute *attr, char *buf)
{
	struct ap_card *ac = to_ap_card(dev);

	return snprintf(buf, PAGE_SIZE, "%d\n", ac->raw_hwtype);
}