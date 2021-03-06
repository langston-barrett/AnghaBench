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
struct tps68470_gpio_data {struct regmap* tps68470_regmap; } ;
struct regmap {int dummy; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  TPS68470_GPIO_CTL_REG_A (unsigned int) ; 
 int /*<<< orphan*/  TPS68470_GPIO_MODE_MASK ; 
 int /*<<< orphan*/  TPS68470_GPIO_MODE_OUT_CMOS ; 
 unsigned int TPS68470_N_REGULAR_GPIO ; 
 struct tps68470_gpio_data* gpiochip_get_data (struct gpio_chip*) ; 
 int regmap_update_bits (struct regmap*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tps68470_gpio_set (struct gpio_chip*,unsigned int,int) ; 

__attribute__((used)) static int tps68470_gpio_output(struct gpio_chip *gc, unsigned int offset,
				int value)
{
	struct tps68470_gpio_data *tps68470_gpio = gpiochip_get_data(gc);
	struct regmap *regmap = tps68470_gpio->tps68470_regmap;

	/* rest are always outputs */
	if (offset >= TPS68470_N_REGULAR_GPIO)
		return 0;

	/* Set the initial value */
	tps68470_gpio_set(gc, offset, value);

	return regmap_update_bits(regmap, TPS68470_GPIO_CTL_REG_A(offset),
				 TPS68470_GPIO_MODE_MASK,
				 TPS68470_GPIO_MODE_OUT_CMOS);
}