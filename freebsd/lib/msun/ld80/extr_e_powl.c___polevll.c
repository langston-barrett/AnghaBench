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

__attribute__((used)) static inline long double
__polevll(long double x, long double *PP, int n)
{
	long double y;
	long double *P;

	P = PP;
	y = *P++;
	do {
		y = y * x + *P++;
	} while (--n);

	return (y);
}