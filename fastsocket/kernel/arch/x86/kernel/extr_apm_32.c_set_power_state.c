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
typedef  int /*<<< orphan*/  u_short ;
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */
 int /*<<< orphan*/  APM_FUNC_SET_STATE ; 
 int APM_SUCCESS ; 
 scalar_t__ apm_bios_call_simple (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int*) ; 

__attribute__((used)) static int set_power_state(u_short what, u_short state)
{
	u32 eax;
	int err;

	if (apm_bios_call_simple(APM_FUNC_SET_STATE, what, state, &eax, &err))
		return err;
	return APM_SUCCESS;
}