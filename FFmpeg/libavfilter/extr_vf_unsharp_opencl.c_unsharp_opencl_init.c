#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  cl_int ;
struct TYPE_8__ {int /*<<< orphan*/  program; TYPE_1__* hwctx; } ;
struct TYPE_9__ {int global; float luma_size_x; float luma_size_y; float chroma_size_x; float chroma_size_y; int initialised; scalar_t__ kernel; scalar_t__ command_queue; TYPE_2__ ocf; } ;
typedef  TYPE_3__ UnsharpOpenCLContext ;
struct TYPE_10__ {TYPE_3__* priv; } ;
struct TYPE_7__ {int /*<<< orphan*/  device_id; int /*<<< orphan*/  context; } ;
typedef  TYPE_4__ AVFilterContext ;

/* Variables and functions */
 int /*<<< orphan*/  AVERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CL_FAIL_ON_ERROR (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  EIO ; 
 scalar_t__ clCreateCommandQueue (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ clCreateKernel (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  clReleaseCommandQueue (scalar_t__) ; 
 int /*<<< orphan*/  clReleaseKernel (scalar_t__) ; 
 int ff_opencl_filter_load_program (TYPE_4__*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ff_opencl_source_unsharp ; 

__attribute__((used)) static int unsharp_opencl_init(AVFilterContext *avctx)
{
    UnsharpOpenCLContext *ctx = avctx->priv;
    cl_int cle;
    int err;

    err = ff_opencl_filter_load_program(avctx, &ff_opencl_source_unsharp, 1);
    if (err < 0)
        goto fail;

    ctx->command_queue = clCreateCommandQueue(ctx->ocf.hwctx->context,
                                              ctx->ocf.hwctx->device_id,
                                              0, &cle);
    CL_FAIL_ON_ERROR(AVERROR(EIO), "Failed to create OpenCL "
                     "command queue %d.\n", cle);

    // Use global kernel if mask size will be too big for the local store..
    ctx->global = (ctx->luma_size_x   > 17.0f ||
                   ctx->luma_size_y   > 17.0f ||
                   ctx->chroma_size_x > 17.0f ||
                   ctx->chroma_size_y > 17.0f);

    ctx->kernel = clCreateKernel(ctx->ocf.program,
                                 ctx->global ? "unsharp_global"
                                             : "unsharp_local", &cle);
    CL_FAIL_ON_ERROR(AVERROR(EIO), "Failed to create kernel %d.\n", cle);

    ctx->initialised = 1;
    return 0;

fail:
    if (ctx->command_queue)
        clReleaseCommandQueue(ctx->command_queue);
    if (ctx->kernel)
        clReleaseKernel(ctx->kernel);
    return err;
}