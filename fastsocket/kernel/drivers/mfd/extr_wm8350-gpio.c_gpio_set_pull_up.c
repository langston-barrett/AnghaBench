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
struct wm8350 {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  WM8350_GPIO_PIN_PULL_UP_CONTROL ; 
 int wm8350_clear_bits (struct wm8350*,int /*<<< orphan*/ ,int) ; 
 int wm8350_set_bits (struct wm8350*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int gpio_set_pull_up(struct wm8350 *wm8350, int gpio, int up)
{
	if (up)
		return wm8350_set_bits(wm8350,
				       WM8350_GPIO_PIN_PULL_UP_CONTROL,
				       1 << gpio);
	else
		return wm8350_clear_bits(wm8350,
					 WM8350_GPIO_PIN_PULL_UP_CONTROL,
					 1 << gpio);
}