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
typedef  int /*<<< orphan*/  float32 ;
typedef  int flag ;

/* Variables and functions */
 int float32_eq (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

flag
__unordsf2(float32 a, float32 b)
{
	/*
	 * The comparison is unordered if either input is a NaN.
	 * Test for this by comparing each operand with itself.
	 * We must perform both comparisons to correctly check for
	 * signalling NaNs.
	 */
	return 1 ^ (float32_eq(a, a) & float32_eq(b, b));
}