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
struct max8997_dev {int /*<<< orphan*/  irqlock; } ;
struct irq_data {int dummy; } ;

/* Variables and functions */
 struct max8997_dev* irq_data_get_irq_chip_data (struct irq_data*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void max8997_irq_lock(struct irq_data *data)
{
	struct max8997_dev *max8997 = irq_data_get_irq_chip_data(data);

	mutex_lock(&max8997->irqlock);
}