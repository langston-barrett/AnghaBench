#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_3__ {int /*<<< orphan*/  (* write_vfta ) (struct e1000_hw*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;
struct TYPE_4__ {TYPE_1__ ops; } ;
struct e1000_hw {TYPE_2__ mac; } ;

/* Variables and functions */
 int /*<<< orphan*/  E1000_VLAN_FILTER_TBL_SIZE ; 
 int /*<<< orphan*/  stub1 (struct e1000_hw*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void igb_clear_vfta(struct e1000_hw *hw)
{
	u32 offset;

	for (offset = E1000_VLAN_FILTER_TBL_SIZE; offset--;)
		hw->mac.ops.write_vfta(hw, offset, 0);
}