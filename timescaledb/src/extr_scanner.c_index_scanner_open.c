#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  indexrel; TYPE_1__* sctx; int /*<<< orphan*/  tablerel; } ;
struct TYPE_4__ {int /*<<< orphan*/  lockmode; int /*<<< orphan*/  index; int /*<<< orphan*/  table; } ;
typedef  int /*<<< orphan*/  Relation ;
typedef  TYPE_2__ InternalScannerCtx ;

/* Variables and functions */
 int /*<<< orphan*/  heap_open (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  index_open (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static Relation
index_scanner_open(InternalScannerCtx *ctx)
{
	ctx->tablerel = heap_open(ctx->sctx->table, ctx->sctx->lockmode);
	ctx->indexrel = index_open(ctx->sctx->index, ctx->sctx->lockmode);
	return ctx->indexrel;
}