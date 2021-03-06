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
typedef  unsigned int u8 ;
struct spmi_regulator {int dummy; } ;
struct regulator_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SPMI_COMMON_REG_VOLTAGE_SET ; 
 struct spmi_regulator* rdev_get_drvdata (struct regulator_dev*) ; 
 int spmi_vreg_write (struct spmi_regulator*,int /*<<< orphan*/ ,unsigned int*,int) ; 

__attribute__((used)) static int spmi_regulator_single_range_set_voltage(struct regulator_dev *rdev,
						   unsigned selector)
{
	struct spmi_regulator *vreg = rdev_get_drvdata(rdev);
	u8 sel = selector;

	/*
	 * Certain types of regulators do not have a range select register so
	 * only voltage set register needs to be written.
	 */
	return spmi_vreg_write(vreg, SPMI_COMMON_REG_VOLTAGE_SET, &sel, 1);
}