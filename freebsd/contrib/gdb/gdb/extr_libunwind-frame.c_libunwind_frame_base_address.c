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
struct libunwind_frame_cache {int /*<<< orphan*/  base; } ;
struct frame_info {int dummy; } ;
typedef  int /*<<< orphan*/  CORE_ADDR ;

/* Variables and functions */
 struct libunwind_frame_cache* libunwind_frame_cache (struct frame_info*,void**) ; 

CORE_ADDR
libunwind_frame_base_address (struct frame_info *next_frame, void **this_cache)
{
  struct libunwind_frame_cache *cache =
    libunwind_frame_cache (next_frame, this_cache);

  return cache->base;
}