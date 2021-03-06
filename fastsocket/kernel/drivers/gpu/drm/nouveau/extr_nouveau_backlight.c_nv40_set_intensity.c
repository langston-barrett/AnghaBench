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
struct nouveau_drm {int /*<<< orphan*/  device; } ;
struct nouveau_device {int dummy; } ;
struct TYPE_2__ {int brightness; } ;
struct backlight_device {TYPE_1__ props; } ;

/* Variables and functions */
 int /*<<< orphan*/  NV40_PMC_BACKLIGHT ; 
 int NV40_PMC_BACKLIGHT_MASK ; 
 struct nouveau_drm* bl_get_data (struct backlight_device*) ; 
 struct nouveau_device* nv_device (int /*<<< orphan*/ ) ; 
 int nv_rd32 (struct nouveau_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nv_wr32 (struct nouveau_device*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int
nv40_set_intensity(struct backlight_device *bd)
{
	struct nouveau_drm *drm = bl_get_data(bd);
	struct nouveau_device *device = nv_device(drm->device);
	int val = bd->props.brightness;
	int reg = nv_rd32(device, NV40_PMC_BACKLIGHT);

	nv_wr32(device, NV40_PMC_BACKLIGHT,
		 (val << 16) | (reg & ~NV40_PMC_BACKLIGHT_MASK));

	return 0;
}