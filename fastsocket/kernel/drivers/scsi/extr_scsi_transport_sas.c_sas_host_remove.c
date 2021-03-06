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
struct transport_container {int dummy; } ;
struct device {int dummy; } ;
struct Scsi_Host {int dummy; } ;

/* Variables and functions */
 struct Scsi_Host* dev_to_shost (struct device*) ; 
 int /*<<< orphan*/  sas_bsg_remove (struct Scsi_Host*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int sas_host_remove(struct transport_container *tc, struct device *dev,
			   struct device *cdev)
{
	struct Scsi_Host *shost = dev_to_shost(dev);

	sas_bsg_remove(shost, NULL);

	return 0;
}