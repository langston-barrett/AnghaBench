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
 unsigned int DIV_ROUND_UP (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  UNIPHIER_GPIO_LINES_PER_BANK ; 

__attribute__((used)) static unsigned int uniphier_gpio_get_nbanks(unsigned int ngpio)
{
	return DIV_ROUND_UP(ngpio, UNIPHIER_GPIO_LINES_PER_BANK);
}