#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u08b_t ;
struct TYPE_5__ {size_t bCnt; int /*<<< orphan*/ * T; } ;
struct TYPE_6__ {int /*<<< orphan*/  X; TYPE_1__ h; int /*<<< orphan*/ * b; } ;
typedef  TYPE_2__ Skein1024_Ctxt_t ;

/* Variables and functions */
 size_t SKEIN1024_BLOCK_BYTES ; 
 int /*<<< orphan*/  SKEIN_FAIL ; 
 int SKEIN_SUCCESS ; 
 int /*<<< orphan*/  SKEIN_T1_FLAG_FINAL ; 
 int /*<<< orphan*/  Skein1024_Process_Block (TYPE_2__*,int /*<<< orphan*/ *,int,size_t) ; 
 int /*<<< orphan*/  Skein_Assert (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Skein_Put64_LSB_First (int /*<<< orphan*/ *,int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,size_t) ; 

int Skein1024_Final_Pad(Skein1024_Ctxt_t *ctx, u08b_t *hashVal)
    {
    Skein_Assert(ctx->h.bCnt <= SKEIN1024_BLOCK_BYTES,SKEIN_FAIL);    /* catch uninitialized context */

    ctx->h.T[1] |= SKEIN_T1_FLAG_FINAL;        /* tag as the final block */
    if (ctx->h.bCnt < SKEIN1024_BLOCK_BYTES)   /* zero pad b[] if necessary */
        memset(&ctx->b[ctx->h.bCnt],0,SKEIN1024_BLOCK_BYTES - ctx->h.bCnt);
    Skein1024_Process_Block(ctx,ctx->b,1,ctx->h.bCnt);    /* process the final block */
    
    Skein_Put64_LSB_First(hashVal,ctx->X,SKEIN1024_BLOCK_BYTES);   /* "output" the state bytes */
    
    return SKEIN_SUCCESS;
    }