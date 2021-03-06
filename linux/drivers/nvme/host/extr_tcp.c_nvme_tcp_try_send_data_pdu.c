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
struct nvme_tcp_request {int offset; int /*<<< orphan*/  data_sent; int /*<<< orphan*/  state; struct nvme_tcp_data_pdu* pdu; struct nvme_tcp_queue* queue; } ;
struct nvme_tcp_queue {int /*<<< orphan*/  snd_hash; scalar_t__ data_digest; int /*<<< orphan*/  sock; scalar_t__ hdr_digest; } ;
struct nvme_tcp_data_pdu {int dummy; } ;

/* Variables and functions */
 int EAGAIN ; 
 int MSG_DONTWAIT ; 
 int MSG_MORE ; 
 int /*<<< orphan*/  NVME_TCP_SEND_DATA ; 
 int /*<<< orphan*/  WRITE ; 
 int /*<<< orphan*/  crypto_ahash_init (int /*<<< orphan*/ ) ; 
 int kernel_sendpage (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int,int) ; 
 int /*<<< orphan*/  nvme_tcp_hdgst (int /*<<< orphan*/ ,struct nvme_tcp_data_pdu*,int) ; 
 int nvme_tcp_hdgst_len (struct nvme_tcp_queue*) ; 
 int /*<<< orphan*/  nvme_tcp_init_iter (struct nvme_tcp_request*,int /*<<< orphan*/ ) ; 
 scalar_t__ offset_in_page (struct nvme_tcp_data_pdu*) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  virt_to_page (struct nvme_tcp_data_pdu*) ; 

__attribute__((used)) static int nvme_tcp_try_send_data_pdu(struct nvme_tcp_request *req)
{
	struct nvme_tcp_queue *queue = req->queue;
	struct nvme_tcp_data_pdu *pdu = req->pdu;
	u8 hdgst = nvme_tcp_hdgst_len(queue);
	int len = sizeof(*pdu) - req->offset + hdgst;
	int ret;

	if (queue->hdr_digest && !req->offset)
		nvme_tcp_hdgst(queue->snd_hash, pdu, sizeof(*pdu));

	ret = kernel_sendpage(queue->sock, virt_to_page(pdu),
			offset_in_page(pdu) + req->offset, len,
			MSG_DONTWAIT | MSG_MORE);
	if (unlikely(ret <= 0))
		return ret;

	len -= ret;
	if (!len) {
		req->state = NVME_TCP_SEND_DATA;
		if (queue->data_digest)
			crypto_ahash_init(queue->snd_hash);
		if (!req->data_sent)
			nvme_tcp_init_iter(req, WRITE);
		return 1;
	}
	req->offset += ret;

	return -EAGAIN;
}