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
typedef  int u8 ;
struct hnae3_handle {int dummy; } ;
struct hclgevf_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  HCLGE_MBX_SET_VLAN ; 
 int /*<<< orphan*/  HCLGE_MBX_VLAN_RX_OFF_CFG ; 
 struct hclgevf_dev* hclgevf_ae_get_hdev (struct hnae3_handle*) ; 
 int hclgevf_send_mbx_msg (struct hclgevf_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int hclgevf_en_hw_strip_rxvtag(struct hnae3_handle *handle, bool enable)
{
	struct hclgevf_dev *hdev = hclgevf_ae_get_hdev(handle);
	u8 msg_data;

	msg_data = enable ? 1 : 0;
	return hclgevf_send_mbx_msg(hdev, HCLGE_MBX_SET_VLAN,
				    HCLGE_MBX_VLAN_RX_OFF_CFG, &msg_data,
				    1, false, NULL, 0);
}