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
struct vc_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  set_console (unsigned char) ; 

__attribute__((used)) static void k_cons(struct vc_data *vc, unsigned char value, char up_flag)
{
	if (up_flag)
		return;
	set_console(value);
}