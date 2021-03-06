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
struct hdmi_drm_infoframe {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int hdmi_drm_infoframe_check (struct hdmi_drm_infoframe*) ; 
 int hdmi_drm_infoframe_pack_only (struct hdmi_drm_infoframe*,void*,size_t) ; 

ssize_t hdmi_drm_infoframe_pack(struct hdmi_drm_infoframe *frame,
				void *buffer, size_t size)
{
	int ret;

	ret = hdmi_drm_infoframe_check(frame);
	if (ret)
		return ret;

	return hdmi_drm_infoframe_pack_only(frame, buffer, size);
}