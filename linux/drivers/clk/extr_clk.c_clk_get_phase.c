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
struct clk {int /*<<< orphan*/  core; } ;

/* Variables and functions */
 int clk_core_get_phase (int /*<<< orphan*/ ) ; 

int clk_get_phase(struct clk *clk)
{
	if (!clk)
		return 0;

	return clk_core_get_phase(clk->core);
}