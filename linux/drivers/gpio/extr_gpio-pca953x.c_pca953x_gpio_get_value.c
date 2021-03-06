#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct pca953x_chip {int /*<<< orphan*/  i2c_lock; int /*<<< orphan*/  regmap; TYPE_1__* regs; } ;
struct gpio_chip {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  input; } ;

/* Variables and functions */
 unsigned int BANK_SZ ; 
 int BIT (unsigned int) ; 
 struct pca953x_chip* gpiochip_get_data (struct gpio_chip*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int pca953x_recalc_addr (struct pca953x_chip*,int /*<<< orphan*/ ,unsigned int,int,int) ; 
 int regmap_read (int /*<<< orphan*/ ,int,int*) ; 

__attribute__((used)) static int pca953x_gpio_get_value(struct gpio_chip *gc, unsigned off)
{
	struct pca953x_chip *chip = gpiochip_get_data(gc);
	u8 inreg = pca953x_recalc_addr(chip, chip->regs->input, off,
				       true, false);
	u8 bit = BIT(off % BANK_SZ);
	u32 reg_val;
	int ret;

	mutex_lock(&chip->i2c_lock);
	ret = regmap_read(chip->regmap, inreg, &reg_val);
	mutex_unlock(&chip->i2c_lock);
	if (ret < 0) {
		/* NOTE:  diagnostic already emitted; that's all we should
		 * do unless gpio_*_value_cansleep() calls become different
		 * from their nonsleeping siblings (and report faults).
		 */
		return 0;
	}

	return !!(reg_val & bit);
}