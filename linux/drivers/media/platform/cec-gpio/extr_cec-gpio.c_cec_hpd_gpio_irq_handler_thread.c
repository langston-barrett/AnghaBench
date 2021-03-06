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
struct cec_gpio {int /*<<< orphan*/  hpd_ts; int /*<<< orphan*/  hpd_is_high; int /*<<< orphan*/  adap; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  cec_queue_pin_hpd_event (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static irqreturn_t cec_hpd_gpio_irq_handler_thread(int irq, void *priv)
{
	struct cec_gpio *cec = priv;

	cec_queue_pin_hpd_event(cec->adap, cec->hpd_is_high, cec->hpd_ts);
	return IRQ_HANDLED;
}