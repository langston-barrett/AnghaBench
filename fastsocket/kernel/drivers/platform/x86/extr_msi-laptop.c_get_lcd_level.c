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
typedef  scalar_t__ u8 ;

/* Variables and functions */
 int /*<<< orphan*/  MSI_EC_COMMAND_LCD_LEVEL ; 
 int ec_transaction (int /*<<< orphan*/ ,scalar_t__*,int,scalar_t__*,int,int) ; 

__attribute__((used)) static int get_lcd_level(void)
{
	u8 wdata = 0, rdata;
	int result;

	result = ec_transaction(MSI_EC_COMMAND_LCD_LEVEL, &wdata, 1, &rdata, 1, 1);
	if (result < 0)
		return result;

	return (int) rdata / 31;
}