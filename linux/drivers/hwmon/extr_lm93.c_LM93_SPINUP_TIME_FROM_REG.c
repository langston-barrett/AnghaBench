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
typedef  int u8 ;

/* Variables and functions */
 int* lm93_spinup_time_map ; 

__attribute__((used)) static int LM93_SPINUP_TIME_FROM_REG(u8 reg)
{
	return lm93_spinup_time_map[reg >> 5 & 0x07];
}