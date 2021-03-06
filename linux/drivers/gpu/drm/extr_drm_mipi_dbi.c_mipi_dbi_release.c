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
struct mipi_dbi_dev {int dummy; } ;
struct drm_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_DEBUG_DRIVER (char*) ; 
 int /*<<< orphan*/  drm_dev_fini (struct drm_device*) ; 
 int /*<<< orphan*/  drm_mode_config_cleanup (struct drm_device*) ; 
 struct mipi_dbi_dev* drm_to_mipi_dbi_dev (struct drm_device*) ; 
 int /*<<< orphan*/  kfree (struct mipi_dbi_dev*) ; 

void mipi_dbi_release(struct drm_device *drm)
{
	struct mipi_dbi_dev *dbidev = drm_to_mipi_dbi_dev(drm);

	DRM_DEBUG_DRIVER("\n");

	drm_mode_config_cleanup(drm);
	drm_dev_fini(drm);
	kfree(dbidev);
}