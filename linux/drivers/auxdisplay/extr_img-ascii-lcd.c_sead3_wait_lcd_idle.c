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
struct img_ascii_lcd_ctx {scalar_t__ offset; int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 scalar_t__ SEAD3_REG_CPLD_DATA ; 
 unsigned int SEAD3_REG_CPLD_DATA_BUSY ; 
 scalar_t__ SEAD3_REG_LCD_CTRL ; 
 int regmap_read (int /*<<< orphan*/ ,scalar_t__,unsigned int*) ; 
 int sead3_wait_sm_idle (struct img_ascii_lcd_ctx*) ; 

__attribute__((used)) static int sead3_wait_lcd_idle(struct img_ascii_lcd_ctx *ctx)
{
	unsigned int cpld_data;
	int err;

	err = sead3_wait_sm_idle(ctx);
	if (err)
		return err;

	do {
		err = regmap_read(ctx->regmap,
				  ctx->offset + SEAD3_REG_LCD_CTRL,
				  &cpld_data);
		if (err)
			return err;

		err = sead3_wait_sm_idle(ctx);
		if (err)
			return err;

		err = regmap_read(ctx->regmap,
				  ctx->offset + SEAD3_REG_CPLD_DATA,
				  &cpld_data);
		if (err)
			return err;
	} while (cpld_data & SEAD3_REG_CPLD_DATA_BUSY);

	return 0;
}