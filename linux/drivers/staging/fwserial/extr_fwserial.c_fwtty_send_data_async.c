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
struct fwtty_transaction {int /*<<< orphan*/  fw_txn; struct fwtty_port* port; int /*<<< orphan*/  callback; } ;
struct fwtty_port {int dummy; } ;
struct fwtty_peer {int generation; int /*<<< orphan*/  speed; int /*<<< orphan*/  node_id; TYPE_1__* serial; } ;
typedef  int /*<<< orphan*/  fwtty_transaction_cb ;
struct TYPE_2__ {int /*<<< orphan*/  card; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  fw_send_request (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,unsigned long long,void*,size_t,int /*<<< orphan*/ ,struct fwtty_transaction*) ; 
 int /*<<< orphan*/  fwtty_common_callback ; 
 int /*<<< orphan*/  fwtty_txn_cache ; 
 struct fwtty_transaction* kmem_cache_alloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  smp_rmb () ; 

__attribute__((used)) static int fwtty_send_data_async(struct fwtty_peer *peer, int tcode,
				 unsigned long long addr, void *payload,
				 size_t len, fwtty_transaction_cb callback,
				 struct fwtty_port *port)
{
	struct fwtty_transaction *txn;
	int generation;

	txn = kmem_cache_alloc(fwtty_txn_cache, GFP_ATOMIC);
	if (!txn)
		return -ENOMEM;

	txn->callback = callback;
	txn->port = port;

	generation = peer->generation;
	smp_rmb();
	fw_send_request(peer->serial->card, &txn->fw_txn, tcode,
			peer->node_id, generation, peer->speed, addr, payload,
			len, fwtty_common_callback, txn);
	return 0;
}