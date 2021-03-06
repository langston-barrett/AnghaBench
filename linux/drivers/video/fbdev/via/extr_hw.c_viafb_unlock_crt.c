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
 int /*<<< orphan*/  BIT0 ; 
 int /*<<< orphan*/  BIT7 ; 
 int /*<<< orphan*/  CR11 ; 
 int /*<<< orphan*/  CR47 ; 
 int /*<<< orphan*/  VIACR ; 
 int /*<<< orphan*/  viafb_write_reg_mask (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void viafb_unlock_crt(void)
{
	viafb_write_reg_mask(CR11, VIACR, 0, BIT7);
	viafb_write_reg_mask(CR47, VIACR, 0, BIT0);
}