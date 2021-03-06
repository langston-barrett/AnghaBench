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
struct auo_pixcir_ts {TYPE_1__* pdata; } ;
struct TYPE_2__ {int /*<<< orphan*/  gpio_rst; } ;

/* Variables and functions */
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void auo_pixcir_reset(void *data)
{
	struct auo_pixcir_ts *ts = data;

	gpio_set_value(ts->pdata->gpio_rst, 0);
}