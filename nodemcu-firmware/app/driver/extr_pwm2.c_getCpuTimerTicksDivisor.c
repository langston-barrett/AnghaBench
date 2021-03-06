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
typedef  int /*<<< orphan*/  uint8_t ;

/* Variables and functions */
 int /*<<< orphan*/  PWM2_TMR_MAGIC_160MHZ ; 
 int /*<<< orphan*/  PWM2_TMR_MAGIC_80MHZ ; 
 int system_get_cpu_freq () ; 

__attribute__((used)) static uint8_t getCpuTimerTicksDivisor() {
  return system_get_cpu_freq() == 80 ? PWM2_TMR_MAGIC_80MHZ : PWM2_TMR_MAGIC_160MHZ;
}