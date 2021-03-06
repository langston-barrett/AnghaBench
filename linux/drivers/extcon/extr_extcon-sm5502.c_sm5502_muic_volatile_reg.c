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
struct device {int dummy; } ;

/* Variables and functions */
#define  SM5502_REG_INTMASK1 129 
#define  SM5502_REG_INTMASK2 128 

__attribute__((used)) static bool sm5502_muic_volatile_reg(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case SM5502_REG_INTMASK1:
	case SM5502_REG_INTMASK2:
		return true;
	default:
		break;
	}
	return false;
}