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
struct TYPE_2__ {unsigned int npwm; int /*<<< orphan*/ * pwms; } ;
struct stm32_pwm {TYPE_1__ chip; } ;
struct platform_device {int dummy; } ;

/* Variables and functions */
 struct stm32_pwm* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  pwm_disable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pwmchip_remove (TYPE_1__*) ; 

__attribute__((used)) static int stm32_pwm_remove(struct platform_device *pdev)
{
	struct stm32_pwm *priv = platform_get_drvdata(pdev);
	unsigned int i;

	for (i = 0; i < priv->chip.npwm; i++)
		pwm_disable(&priv->chip.pwms[i]);

	pwmchip_remove(&priv->chip);

	return 0;
}