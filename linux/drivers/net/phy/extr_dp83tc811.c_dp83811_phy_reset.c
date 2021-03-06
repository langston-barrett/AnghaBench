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
struct phy_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DP83811_HW_RESET ; 
 int /*<<< orphan*/  MII_DP83811_RESET_CTRL ; 
 int phy_write (struct phy_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int dp83811_phy_reset(struct phy_device *phydev)
{
	int err;

	err = phy_write(phydev, MII_DP83811_RESET_CTRL, DP83811_HW_RESET);
	if (err < 0)
		return err;

	return 0;
}