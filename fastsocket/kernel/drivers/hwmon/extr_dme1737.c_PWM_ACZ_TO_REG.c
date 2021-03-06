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

__attribute__((used)) static inline int PWM_ACZ_TO_REG(int val, int reg)
{
	int acz = (val == 4) ? 2 : val - 1;

	return (reg & 0x1f) | ((acz & 0x07) << 5);
}