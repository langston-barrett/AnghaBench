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
struct its_vpe {int dummy; } ;
struct its_cmd_info {int /*<<< orphan*/  cmd_type; } ;

/* Variables and functions */
 int /*<<< orphan*/  INVALL_VPE ; 
 int its_send_vpe_cmd (struct its_vpe*,struct its_cmd_info*) ; 

int its_invall_vpe(struct its_vpe *vpe)
{
	struct its_cmd_info info = {
		.cmd_type = INVALL_VPE,
	};

	return its_send_vpe_cmd(vpe, &info);
}