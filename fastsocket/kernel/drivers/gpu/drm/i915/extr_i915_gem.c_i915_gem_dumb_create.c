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
struct drm_mode_create_dumb {int pitch; int width; int bpp; int size; int height; int /*<<< orphan*/  handle; } ;
struct drm_file {int dummy; } ;
struct drm_device {int dummy; } ;

/* Variables and functions */
 int ALIGN (int,int) ; 
 int i915_gem_create (struct drm_file*,struct drm_device*,int,int /*<<< orphan*/ *) ; 

int
i915_gem_dumb_create(struct drm_file *file,
		     struct drm_device *dev,
		     struct drm_mode_create_dumb *args)
{
	/* have to work out size/pitch and return them */
	args->pitch = ALIGN(args->width * ((args->bpp + 7) / 8), 64);
	args->size = args->pitch * args->height;
	return i915_gem_create(file, dev,
			       args->size, &args->handle);
}