#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  (* set_mode ) (struct xgbe_prv_data*,int /*<<< orphan*/ ) ;} ;
struct TYPE_6__ {TYPE_2__ phy_impl; } ;
struct TYPE_4__ {int /*<<< orphan*/  (* set_speed ) (struct xgbe_prv_data*,int /*<<< orphan*/ ) ;} ;
struct xgbe_prv_data {TYPE_3__ phy_if; TYPE_1__ hw_if; } ;

/* Variables and functions */
 int /*<<< orphan*/  SPEED_1000 ; 
 int /*<<< orphan*/  XGBE_MODE_SGMII_1000 ; 
 int /*<<< orphan*/  stub1 (struct xgbe_prv_data*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (struct xgbe_prv_data*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void xgbe_sgmii_1000_mode(struct xgbe_prv_data *pdata)
{
	/* Set MAC to 1G speed */
	pdata->hw_if.set_speed(pdata, SPEED_1000);

	/* Call PHY implementation support to complete rate change */
	pdata->phy_if.phy_impl.set_mode(pdata, XGBE_MODE_SGMII_1000);
}