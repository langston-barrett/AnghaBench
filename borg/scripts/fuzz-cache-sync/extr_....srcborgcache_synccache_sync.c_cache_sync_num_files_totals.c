#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint64_t ;
struct TYPE_6__ {int /*<<< orphan*/  num_files; } ;
struct TYPE_7__ {TYPE_1__ totals; } ;
struct TYPE_8__ {TYPE_2__ user; } ;
struct TYPE_9__ {TYPE_3__ ctx; } ;
typedef  TYPE_4__ CacheSyncCtx ;

/* Variables and functions */

__attribute__((used)) static uint64_t
cache_sync_num_files_totals(const CacheSyncCtx *ctx)
{
    return ctx->ctx.user.totals.num_files;
}