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
struct fnic {size_t state; } ;
struct fc_lport {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  class_to_shost (struct device*) ; 
 char** fnic_state_str ; 
 struct fnic* lport_priv (struct fc_lport*) ; 
 struct fc_lport* shost_priv (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (char*,int /*<<< orphan*/ ,char*,char*) ; 

__attribute__((used)) static ssize_t fnic_show_state(struct device *dev,
			       struct device_attribute *attr, char *buf)
{
	struct fc_lport *lp = shost_priv(class_to_shost(dev));
	struct fnic *fnic = lport_priv(lp);

	return snprintf(buf, PAGE_SIZE, "%s\n", fnic_state_str[fnic->state]);
}