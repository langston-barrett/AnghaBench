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
struct device_node {int dummy; } ;

/* Variables and functions */
 scalar_t__ of_find_property (struct device_node*,char*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static bool sunxi_pctrl_has_drive_prop(struct device_node *node)
{
	return of_find_property(node, "drive-strength", NULL) ||
		of_find_property(node, "allwinner,drive", NULL);
}