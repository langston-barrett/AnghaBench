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
struct lan743x_adapter {int dummy; } ;

/* Variables and functions */
 int lan743x_phy_reset (struct lan743x_adapter*) ; 

__attribute__((used)) static int lan743x_phy_init(struct lan743x_adapter *adapter)
{
	return lan743x_phy_reset(adapter);
}