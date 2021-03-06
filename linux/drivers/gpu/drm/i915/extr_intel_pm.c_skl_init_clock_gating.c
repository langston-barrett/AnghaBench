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
struct drm_i915_private {int dummy; } ;

/* Variables and functions */
 int FBC_LLC_FULLY_OPEN ; 
 int /*<<< orphan*/  FBC_LLC_READ_CTRL ; 
 int I915_READ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  I915_WRITE (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ILK_DPFC_CHICKEN ; 
 int ILK_DPFC_NUKE_ON_ANY_MODIFICATION ; 
 int /*<<< orphan*/  gen9_init_clock_gating (struct drm_i915_private*) ; 

__attribute__((used)) static void skl_init_clock_gating(struct drm_i915_private *dev_priv)
{
	gen9_init_clock_gating(dev_priv);

	/* WAC6entrylatency:skl */
	I915_WRITE(FBC_LLC_READ_CTRL, I915_READ(FBC_LLC_READ_CTRL) |
		   FBC_LLC_FULLY_OPEN);

	/* WaFbcNukeOnHostModify:skl */
	I915_WRITE(ILK_DPFC_CHICKEN, I915_READ(ILK_DPFC_CHICKEN) |
		   ILK_DPFC_NUKE_ON_ANY_MODIFICATION);
}