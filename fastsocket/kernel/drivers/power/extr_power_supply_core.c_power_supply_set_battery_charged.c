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
struct power_supply {scalar_t__ type; int /*<<< orphan*/  (* set_charged ) (struct power_supply*) ;} ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ POWER_SUPPLY_TYPE_BATTERY ; 
 int /*<<< orphan*/  stub1 (struct power_supply*) ; 

int power_supply_set_battery_charged(struct power_supply *psy)
{
	if (psy->type == POWER_SUPPLY_TYPE_BATTERY && psy->set_charged) {
		psy->set_charged(psy);
		return 0;
	}

	return -EINVAL;
}