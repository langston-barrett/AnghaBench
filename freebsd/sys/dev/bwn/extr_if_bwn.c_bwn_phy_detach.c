#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  (* detach ) (struct bwn_mac*) ;} ;
struct bwn_mac {TYPE_1__ mac_phy; } ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct bwn_mac*) ; 

__attribute__((used)) static void
bwn_phy_detach(struct bwn_mac *mac)
{

	if (mac->mac_phy.detach != NULL)
		mac->mac_phy.detach(mac);
}