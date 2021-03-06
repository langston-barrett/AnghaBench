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
typedef  int /*<<< orphan*/  u_int16_t ;
struct agg_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  AGG_WR (struct agg_info*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  PORT_WAVCACHE_DATA ; 
 int /*<<< orphan*/  PORT_WAVCACHE_INDEX ; 

__attribute__((used)) static void
wc_wrreg(struct agg_info *ess, u_int16_t reg, u_int16_t data)
{
	AGG_WR(ess, PORT_WAVCACHE_INDEX, reg, 2);
	AGG_WR(ess, PORT_WAVCACHE_DATA, data, 2);
}