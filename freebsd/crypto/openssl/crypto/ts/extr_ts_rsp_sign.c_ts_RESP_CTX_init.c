#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/ * tst_info; int /*<<< orphan*/ * response; int /*<<< orphan*/ * request; } ;
typedef  TYPE_1__ TS_RESP_CTX ;

/* Variables and functions */

__attribute__((used)) static void ts_RESP_CTX_init(TS_RESP_CTX *ctx)
{
    ctx->request = NULL;
    ctx->response = NULL;
    ctx->tst_info = NULL;
}