#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct video_scale_info {int dummy; } ;
struct obs_core_video {int /*<<< orphan*/  video; } ;
struct TYPE_2__ {struct obs_core_video video; } ;

/* Variables and functions */
 TYPE_1__* obs ; 
 int /*<<< orphan*/  start_raw_video (int /*<<< orphan*/ ,struct video_scale_info const*,void (*) (void*,struct video_data*),void*) ; 

void obs_add_raw_video_callback(const struct video_scale_info *conversion,
				void (*callback)(void *param,
						 struct video_data *frame),
				void *param)
{
	struct obs_core_video *video = &obs->video;
	if (!obs)
		return;
	start_raw_video(video->video, conversion, callback, param);
}