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
typedef  int /*<<< orphan*/  u32 ;
struct intel_guc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GUC_POWER_D0 ; 
 int /*<<< orphan*/  INTEL_GUC_ACTION_EXIT_S_STATE ; 
 int intel_guc_send (struct intel_guc*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

int intel_guc_resume(struct intel_guc *guc)
{
	u32 action[] = {
		INTEL_GUC_ACTION_EXIT_S_STATE,
		GUC_POWER_D0,
	};

	return intel_guc_send(guc, action, ARRAY_SIZE(action));
}