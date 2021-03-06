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
typedef  int /*<<< orphan*/  u_int ;
struct grid_cell {int dummy; } ;
struct grid {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  grid_set_cells (struct grid*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct grid_cell const*,char const*,size_t) ; 
 int /*<<< orphan*/  grid_view_x (struct grid*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  grid_view_y (struct grid*,int /*<<< orphan*/ ) ; 

void
grid_view_set_cells(struct grid *gd, u_int px, u_int py,
    const struct grid_cell *gc, const char *s, size_t slen)
{
	grid_set_cells(gd, grid_view_x(gd, px), grid_view_y(gd, py), gc, s,
	    slen);
}