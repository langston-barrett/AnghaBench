#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct qlcnic_vf_info {scalar_t__ rx_ctx_id; } ;
struct TYPE_2__ {scalar_t__* arg; } ;
struct qlcnic_cmd_args {TYPE_1__ req; } ;

/* Variables and functions */
 int EINVAL ; 

__attribute__((used)) static int qlcnic_sriov_validate_cfg_rss(struct qlcnic_vf_info *vf,
					 struct qlcnic_cmd_args *cmd)
{
	if (cmd->req.arg[1] != vf->rx_ctx_id)
		return -EINVAL;

	return 0;
}