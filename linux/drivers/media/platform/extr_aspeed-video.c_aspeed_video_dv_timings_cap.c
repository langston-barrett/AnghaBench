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
struct v4l2_dv_timings_cap {int dummy; } ;
struct file {int dummy; } ;

/* Variables and functions */
 struct v4l2_dv_timings_cap aspeed_video_timings_cap ; 

__attribute__((used)) static int aspeed_video_dv_timings_cap(struct file *file, void *fh,
				       struct v4l2_dv_timings_cap *cap)
{
	*cap = aspeed_video_timings_cap;

	return 0;
}