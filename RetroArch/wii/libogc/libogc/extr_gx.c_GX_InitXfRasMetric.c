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

/* Variables and functions */
 int /*<<< orphan*/  GX_LOAD_BP_REG (int) ; 
 int /*<<< orphan*/  GX_LOAD_XF_REG (int,int) ; 

void GX_InitXfRasMetric()
{
	GX_LOAD_BP_REG(0x2402C022);
	GX_LOAD_XF_REG(0x1006,0x31000);
}