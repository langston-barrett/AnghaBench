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
struct TYPE_4__ {TYPE_2__* codec_setup; } ;
typedef  TYPE_1__ vorbis_info ;
struct TYPE_5__ {int* blocksizes; int halfrate_flag; } ;
typedef  TYPE_2__ codec_setup_info ;

/* Variables and functions */

int vorbis_synthesis_halfrate(vorbis_info *vi,int flag){
  /* set / clear half-sample-rate mode */
  codec_setup_info     *ci=vi->codec_setup;

  /* right now, our MDCT can't handle < 64 sample windows. */
  if(ci->blocksizes[0]<=64 && flag)return -1;
  ci->halfrate_flag=(flag?1:0);
  return 0;
}