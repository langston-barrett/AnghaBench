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
struct sclp_register {int dummy; } ;
typedef  enum sclp_pm_event { ____Placeholder_sclp_pm_event } sclp_pm_event ;

/* Variables and functions */
 int /*<<< orphan*/  sclp_console_pm_event (int) ; 

__attribute__((used)) static void sclp_rw_pm_event(struct sclp_register *reg,
			     enum sclp_pm_event sclp_pm_event)
{
	sclp_console_pm_event(sclp_pm_event);
}