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
typedef  int u32 ;
struct ssb_chipcommon {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SSB_CHIPCO_GPIOIN ; 
 int chipco_read32 (struct ssb_chipcommon*,int /*<<< orphan*/ ) ; 

u32 ssb_chipco_gpio_in(struct ssb_chipcommon *cc, u32 mask)
{
	return chipco_read32(cc, SSB_CHIPCO_GPIOIN) & mask;
}