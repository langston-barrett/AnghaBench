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
typedef  int /*<<< orphan*/  ZSTD_CCtx ;

/* Variables and functions */
 size_t ZSTD_compress2 (int /*<<< orphan*/ * const,void*,size_t,void const*,size_t) ; 

__attribute__((used)) static size_t local_defaultCompress(
                    const void* srcBuffer, size_t srcSize,
                    void* dstBuffer, size_t dstSize,
                    void* addArgs)
{
    ZSTD_CCtx* const cctx = (ZSTD_CCtx*)addArgs;
    return ZSTD_compress2(cctx, dstBuffer, dstSize, srcBuffer, srcSize);
}