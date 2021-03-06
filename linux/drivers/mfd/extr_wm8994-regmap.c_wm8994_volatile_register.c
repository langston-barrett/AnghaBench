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
#define  WM8958_MIC_DETECT_3 135 
#define  WM8994_DC_SERVO_1 134 
#define  WM8994_DC_SERVO_4E 133 
#define  WM8994_DC_SERVO_READBACK 132 
#define  WM8994_INTERRUPT_STATUS_1 131 
#define  WM8994_INTERRUPT_STATUS_2 130 
#define  WM8994_RATE_STATUS 129 
#define  WM8994_SOFTWARE_RESET 128 

__attribute__((used)) static bool wm8994_volatile_register(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case WM8994_SOFTWARE_RESET:
	case WM8994_DC_SERVO_1:
	case WM8994_DC_SERVO_READBACK:
	case WM8994_RATE_STATUS:
	case WM8958_MIC_DETECT_3:
	case WM8994_DC_SERVO_4E:
	case WM8994_INTERRUPT_STATUS_1:
	case WM8994_INTERRUPT_STATUS_2:
		return true;
	default:
		return false;
	}
}