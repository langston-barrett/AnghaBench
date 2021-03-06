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
struct mlx4_vhcr {int op_modifier; int in_modifier; int /*<<< orphan*/  out_param; int /*<<< orphan*/  in_param; } ;
struct mlx4_dev {int dummy; } ;
struct mlx4_cmd_mailbox {int dummy; } ;
struct mlx4_cmd_info {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
#define  RES_COUNTER 136 
#define  RES_CQ 135 
#define  RES_MAC 134 
#define  RES_MPT 133 
#define  RES_MTT 132 
#define  RES_QP 131 
#define  RES_SRQ 130 
#define  RES_VLAN 129 
#define  RES_XRCD 128 
 int counter_alloc_res (struct mlx4_dev*,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int cq_alloc_res (struct mlx4_dev*,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int mac_alloc_res (struct mlx4_dev*,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int mpt_alloc_res (struct mlx4_dev*,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int mtt_alloc_res (struct mlx4_dev*,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int qp_alloc_res (struct mlx4_dev*,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int srq_alloc_res (struct mlx4_dev*,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int vlan_alloc_res (struct mlx4_dev*,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int xrcdn_alloc_res (struct mlx4_dev*,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

int mlx4_ALLOC_RES_wrapper(struct mlx4_dev *dev, int slave,
			   struct mlx4_vhcr *vhcr,
			   struct mlx4_cmd_mailbox *inbox,
			   struct mlx4_cmd_mailbox *outbox,
			   struct mlx4_cmd_info *cmd)
{
	int err;
	int alop = vhcr->op_modifier;

	switch (vhcr->in_modifier) {
	case RES_QP:
		err = qp_alloc_res(dev, slave, vhcr->op_modifier, alop,
				   vhcr->in_param, &vhcr->out_param);
		break;

	case RES_MTT:
		err = mtt_alloc_res(dev, slave, vhcr->op_modifier, alop,
				    vhcr->in_param, &vhcr->out_param);
		break;

	case RES_MPT:
		err = mpt_alloc_res(dev, slave, vhcr->op_modifier, alop,
				    vhcr->in_param, &vhcr->out_param);
		break;

	case RES_CQ:
		err = cq_alloc_res(dev, slave, vhcr->op_modifier, alop,
				   vhcr->in_param, &vhcr->out_param);
		break;

	case RES_SRQ:
		err = srq_alloc_res(dev, slave, vhcr->op_modifier, alop,
				    vhcr->in_param, &vhcr->out_param);
		break;

	case RES_MAC:
		err = mac_alloc_res(dev, slave, vhcr->op_modifier, alop,
				    vhcr->in_param, &vhcr->out_param);
		break;

	case RES_VLAN:
		err = vlan_alloc_res(dev, slave, vhcr->op_modifier, alop,
				    vhcr->in_param, &vhcr->out_param);
		break;

	case RES_COUNTER:
		err = counter_alloc_res(dev, slave, vhcr->op_modifier, alop,
					vhcr->in_param, &vhcr->out_param);
		break;

	case RES_XRCD:
		err = xrcdn_alloc_res(dev, slave, vhcr->op_modifier, alop,
				      vhcr->in_param, &vhcr->out_param);
		break;

	default:
		err = -EINVAL;
		break;
	}

	return err;
}