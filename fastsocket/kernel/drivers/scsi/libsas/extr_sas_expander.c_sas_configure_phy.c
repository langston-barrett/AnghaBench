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
typedef  int /*<<< orphan*/  u8 ;
struct domain_device {int dummy; } ;

/* Variables and functions */
 int sas_configure_present (struct domain_device*,int,int /*<<< orphan*/ *,int*,int*) ; 
 int sas_configure_set (struct domain_device*,int,int /*<<< orphan*/ *,int,int) ; 

__attribute__((used)) static int sas_configure_phy(struct domain_device *dev, int phy_id,
				    u8 *sas_addr, int include)
{
	int index;
	int present;
	int res;

	res = sas_configure_present(dev, phy_id, sas_addr, &index, &present);
	if (res)
		return res;
	if (include ^ present)
		return sas_configure_set(dev, phy_id, sas_addr, index,include);

	return res;
}