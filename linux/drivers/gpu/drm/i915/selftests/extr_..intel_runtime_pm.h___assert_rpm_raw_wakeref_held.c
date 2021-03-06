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
struct intel_runtime_pm {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  WARN_ONCE (int,char*) ; 
 int /*<<< orphan*/  assert_rpm_device_not_suspended (struct intel_runtime_pm*) ; 
 int /*<<< orphan*/  intel_rpm_raw_wakeref_count (int) ; 

__attribute__((used)) static inline void
__assert_rpm_raw_wakeref_held(struct intel_runtime_pm *rpm, int wakeref_count)
{
	assert_rpm_device_not_suspended(rpm);
	WARN_ONCE(!intel_rpm_raw_wakeref_count(wakeref_count),
		  "RPM raw-wakeref not held\n");
}