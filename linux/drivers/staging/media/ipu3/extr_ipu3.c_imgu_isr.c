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
struct imgu_device {int /*<<< orphan*/  css; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_NONE ; 
 int /*<<< orphan*/  IRQ_WAKE_THREAD ; 
 scalar_t__ imgu_css_irq_ack (int /*<<< orphan*/ *) ; 

__attribute__((used)) static irqreturn_t imgu_isr(int irq, void *imgu_ptr)
{
	struct imgu_device *imgu = imgu_ptr;

	/* acknowledge interruption */
	if (imgu_css_irq_ack(&imgu->css) < 0)
		return IRQ_NONE;

	return IRQ_WAKE_THREAD;
}