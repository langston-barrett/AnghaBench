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
struct bignum {int dummy; } ;
typedef  int /*<<< orphan*/  mp_int ;

/* Variables and functions */
 int mp_cmp_d (int /*<<< orphan*/ *,unsigned long) ; 

int 
bignum_cmp_d(const struct bignum *a, unsigned long b)
{
	return mp_cmp_d((mp_int *) a, b);
}