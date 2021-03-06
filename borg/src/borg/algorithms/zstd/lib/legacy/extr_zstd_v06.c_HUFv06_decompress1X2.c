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
typedef  int /*<<< orphan*/  BYTE ;

/* Variables and functions */
 int /*<<< orphan*/  DTable ; 
 size_t ERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HUFv06_CREATE_STATIC_DTABLEX2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HUFv06_MAX_TABLELOG ; 
 size_t HUFv06_decompress1X2_usingDTable (void*,size_t,int /*<<< orphan*/  const*,size_t,int /*<<< orphan*/ ) ; 
 scalar_t__ HUFv06_isError (size_t const) ; 
 size_t HUFv06_readDTableX2 (int /*<<< orphan*/ ,void const*,size_t) ; 
 int /*<<< orphan*/  srcSize_wrong ; 

size_t HUFv06_decompress1X2 (void* dst, size_t dstSize, const void* cSrc, size_t cSrcSize)
{
    HUFv06_CREATE_STATIC_DTABLEX2(DTable, HUFv06_MAX_TABLELOG);
    const BYTE* ip = (const BYTE*) cSrc;

    size_t const errorCode = HUFv06_readDTableX2 (DTable, cSrc, cSrcSize);
    if (HUFv06_isError(errorCode)) return errorCode;
    if (errorCode >= cSrcSize) return ERROR(srcSize_wrong);
    ip += errorCode;
    cSrcSize -= errorCode;

    return HUFv06_decompress1X2_usingDTable (dst, dstSize, ip, cSrcSize, DTable);
}