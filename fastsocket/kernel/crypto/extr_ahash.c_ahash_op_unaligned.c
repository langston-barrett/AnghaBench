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
typedef  int /*<<< orphan*/  u8 ;
struct crypto_ahash {int dummy; } ;
struct ahash_request_priv {scalar_t__ ubuf; struct ahash_request* data; int /*<<< orphan*/  complete; int /*<<< orphan*/  result; } ;
struct TYPE_2__ {int flags; struct ahash_request* data; int /*<<< orphan*/  complete; } ;
struct ahash_request {struct ahash_request_priv* priv; TYPE_1__ base; int /*<<< orphan*/  result; } ;

/* Variables and functions */
 int CRYPTO_TFM_REQ_MAY_SLEEP ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  PTR_ALIGN (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ ahash_align_buffer_size (unsigned int,unsigned long) ; 
 int /*<<< orphan*/  ahash_op_unaligned_done ; 
 int /*<<< orphan*/  ahash_op_unaligned_finish (struct ahash_request*,int) ; 
 unsigned long crypto_ahash_alignmask (struct crypto_ahash*) ; 
 unsigned int crypto_ahash_digestsize (struct crypto_ahash*) ; 
 struct crypto_ahash* crypto_ahash_reqtfm (struct ahash_request*) ; 
 struct ahash_request_priv* kmalloc (scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ahash_op_unaligned(struct ahash_request *req,
			      int (*op)(struct ahash_request *))
{
	struct crypto_ahash *tfm = crypto_ahash_reqtfm(req);
	unsigned long alignmask = crypto_ahash_alignmask(tfm);
	unsigned int ds = crypto_ahash_digestsize(tfm);
	struct ahash_request_priv *priv;
	int err;

	priv = kmalloc(sizeof(*priv) + ahash_align_buffer_size(ds, alignmask),
		       (req->base.flags & CRYPTO_TFM_REQ_MAY_SLEEP) ?
		       GFP_KERNEL : GFP_ATOMIC);
	if (!priv)
		return -ENOMEM;

	priv->result = req->result;
	priv->complete = req->base.complete;
	priv->data = req->base.data;

	req->result = PTR_ALIGN((u8 *)priv->ubuf, alignmask + 1);
	req->base.complete = ahash_op_unaligned_done;
	req->base.data = req;
	req->priv = priv;

	err = op(req);
	ahash_op_unaligned_finish(req, err);

	return err;
}