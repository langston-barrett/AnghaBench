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
typedef  int /*<<< orphan*/  int64_t ;
typedef  int /*<<< orphan*/  VC_CONTAINER_T ;
typedef  int /*<<< orphan*/  VC_CONTAINER_STATUS_T ;

/* Variables and functions */
 int /*<<< orphan*/  MP4_SKIP_FOURCC (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  MP4_SKIP_U8 (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  STREAM_STATUS (int /*<<< orphan*/ *) ; 

__attribute__((used)) static VC_CONTAINER_STATUS_T mp4_read_box_vide_d263( VC_CONTAINER_T *p_ctx, int64_t size )
{
   MP4_SKIP_FOURCC(p_ctx, "vendor");
   MP4_SKIP_U8(p_ctx, "version");
   MP4_SKIP_U8(p_ctx, "level");
   MP4_SKIP_U8(p_ctx, "profile");
   return STREAM_STATUS(p_ctx);
}