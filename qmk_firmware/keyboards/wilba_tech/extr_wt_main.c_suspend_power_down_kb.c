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
 int /*<<< orphan*/  backlight_set_suspend_state (int) ; 

void suspend_power_down_kb(void)
{
#if RGB_BACKLIGHT_ENABLED || MONO_BACKLIGHT_ENABLED
	backlight_set_suspend_state(true);
#endif // RGB_BACKLIGHT_ENABLED || MONO_BACKLIGHT_ENABLED
}