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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u16 ;
struct sock {int dummy; } ;
struct sk_buff {int /*<<< orphan*/  tstamp; } ;
struct mgmt_hdr {void* index; void* len; void* opcode; } ;
struct mgmt_ev_cmd_status {void* opcode; int /*<<< orphan*/  status; } ;

/* Variables and functions */
 int /*<<< orphan*/  BT_DBG (char*,struct sock*,int,int,int /*<<< orphan*/ ) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HCI_CHANNEL_MONITOR ; 
 int /*<<< orphan*/  HCI_SOCK_TRUSTED ; 
 int MGMT_EV_CMD_STATUS ; 
 int /*<<< orphan*/  __net_timestamp (struct sk_buff*) ; 
 struct sk_buff* alloc_skb (int,int /*<<< orphan*/ ) ; 
 void* cpu_to_le16 (int) ; 
 struct sk_buff* create_monitor_ctrl_event (void*,int /*<<< orphan*/ ,int,int,struct mgmt_ev_cmd_status*) ; 
 int /*<<< orphan*/  hci_send_to_channel (int /*<<< orphan*/ ,struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hci_sock_get_cookie (struct sock*) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 void* skb_put (struct sk_buff*,int) ; 
 int sock_queue_rcv_skb (struct sock*,struct sk_buff*) ; 

int mgmt_cmd_status(struct sock *sk, u16 index, u16 cmd, u8 status)
{
	struct sk_buff *skb, *mskb;
	struct mgmt_hdr *hdr;
	struct mgmt_ev_cmd_status *ev;
	int err;

	BT_DBG("sock %p, index %u, cmd %u, status %u", sk, index, cmd, status);

	skb = alloc_skb(sizeof(*hdr) + sizeof(*ev), GFP_KERNEL);
	if (!skb)
		return -ENOMEM;

	hdr = skb_put(skb, sizeof(*hdr));

	hdr->opcode = cpu_to_le16(MGMT_EV_CMD_STATUS);
	hdr->index = cpu_to_le16(index);
	hdr->len = cpu_to_le16(sizeof(*ev));

	ev = skb_put(skb, sizeof(*ev));
	ev->status = status;
	ev->opcode = cpu_to_le16(cmd);

	mskb = create_monitor_ctrl_event(hdr->index, hci_sock_get_cookie(sk),
					 MGMT_EV_CMD_STATUS, sizeof(*ev), ev);
	if (mskb)
		skb->tstamp = mskb->tstamp;
	else
		__net_timestamp(skb);

	err = sock_queue_rcv_skb(sk, skb);
	if (err < 0)
		kfree_skb(skb);

	if (mskb) {
		hci_send_to_channel(HCI_CHANNEL_MONITOR, mskb,
				    HCI_SOCK_TRUSTED, NULL);
		kfree_skb(mskb);
	}

	return err;
}