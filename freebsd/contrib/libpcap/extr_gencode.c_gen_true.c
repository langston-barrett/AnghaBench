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
struct block {int dummy; } ;
typedef  int /*<<< orphan*/  compiler_state_t ;

/* Variables and functions */
 struct block* gen_uncond (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static inline struct block *
gen_true(compiler_state_t *cstate)
{
	return gen_uncond(cstate, 1);
}