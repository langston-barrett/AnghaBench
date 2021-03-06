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
struct vc_data {scalar_t__ vc_origin; } ;

/* Variables and functions */
 int /*<<< orphan*/  say_line (struct vc_data*) ; 
 int spk_parked ; 
 scalar_t__ spk_pos ; 
 int spk_x ; 
 scalar_t__ spk_y ; 

__attribute__((used)) static void top_edge(struct vc_data *vc)
{
	spk_parked |= 0x01;
	spk_pos = vc->vc_origin + 2 * spk_x;
	spk_y = 0;
	say_line(vc);
}