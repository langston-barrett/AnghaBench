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
struct drm_gem_object {struct drm_device* dev; } ;
struct drm_device {TYPE_1__* driver; } ;
struct dma_buf {struct drm_gem_object* priv; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* gem_prime_vunmap ) (struct drm_gem_object*,void*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct drm_gem_object*,void*) ; 

__attribute__((used)) static void drm_gem_dmabuf_vunmap(struct dma_buf *dma_buf, void *vaddr)
{
	struct drm_gem_object *obj = dma_buf->priv;
	struct drm_device *dev = obj->dev;

	dev->driver->gem_prime_vunmap(obj, vaddr);
}