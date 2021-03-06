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

/* Variables and functions */
 int /*<<< orphan*/  CPU_TYPE ; 
 scalar_t__ CPU_TYPE_IS_EC020_PLUS (int /*<<< orphan*/ ) ; 
 int REG_PC ; 
 int /*<<< orphan*/  m68ki_exception_illegal () ; 

void m68k_op_trapf_32(void)
{
	if(CPU_TYPE_IS_EC020_PLUS(CPU_TYPE))
	{
		REG_PC += 4;
		return;
	}
	m68ki_exception_illegal();
}