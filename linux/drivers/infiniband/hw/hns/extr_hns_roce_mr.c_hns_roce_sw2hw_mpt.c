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
struct hns_roce_dev {int dummy; } ;
struct hns_roce_cmd_mailbox {int /*<<< orphan*/  dma; } ;

/* Variables and functions */
 int /*<<< orphan*/  HNS_ROCE_CMD_SW2HW_MPT ; 
 int /*<<< orphan*/  HNS_ROCE_CMD_TIMEOUT_MSECS ; 
 int hns_roce_cmd_mbox (struct hns_roce_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int hns_roce_sw2hw_mpt(struct hns_roce_dev *hr_dev,
			      struct hns_roce_cmd_mailbox *mailbox,
			      unsigned long mpt_index)
{
	return hns_roce_cmd_mbox(hr_dev, mailbox->dma, 0, mpt_index, 0,
				 HNS_ROCE_CMD_SW2HW_MPT,
				 HNS_ROCE_CMD_TIMEOUT_MSECS);
}