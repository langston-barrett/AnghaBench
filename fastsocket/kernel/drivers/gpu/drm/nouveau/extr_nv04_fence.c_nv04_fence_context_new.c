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
struct TYPE_2__ {int /*<<< orphan*/  read; int /*<<< orphan*/  sync; int /*<<< orphan*/  emit; } ;
struct nv04_fence_chan {TYPE_1__ base; } ;
struct nouveau_channel {struct nv04_fence_chan* fence; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct nv04_fence_chan* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nouveau_fence_context_new (TYPE_1__*) ; 
 int /*<<< orphan*/  nv04_fence_emit ; 
 int /*<<< orphan*/  nv04_fence_read ; 
 int /*<<< orphan*/  nv04_fence_sync ; 

__attribute__((used)) static int
nv04_fence_context_new(struct nouveau_channel *chan)
{
	struct nv04_fence_chan *fctx = kzalloc(sizeof(*fctx), GFP_KERNEL);
	if (fctx) {
		nouveau_fence_context_new(&fctx->base);
		fctx->base.emit = nv04_fence_emit;
		fctx->base.sync = nv04_fence_sync;
		fctx->base.read = nv04_fence_read;
		chan->fence = fctx;
		return 0;
	}
	return -ENOMEM;
}