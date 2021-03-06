#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u16 ;
struct panel_drv_data {int /*<<< orphan*/  lock; int /*<<< orphan*/  channel; int /*<<< orphan*/  do_update; int /*<<< orphan*/  te_timeout_work; int /*<<< orphan*/  ext_te_gpio; scalar_t__ te_enabled; int /*<<< orphan*/  enabled; TYPE_1__* pdev; struct omap_dss_device* in; } ;
struct TYPE_10__ {TYPE_4__* dsi; } ;
struct TYPE_7__ {int /*<<< orphan*/  y_res; int /*<<< orphan*/  x_res; } ;
struct TYPE_8__ {TYPE_2__ timings; } ;
struct omap_dss_device {TYPE_5__ ops; TYPE_3__ panel; } ;
struct TYPE_9__ {int (* update ) (struct omap_dss_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct panel_drv_data*) ;int /*<<< orphan*/  (* bus_unlock ) (struct omap_dss_device*) ;int /*<<< orphan*/  (* bus_lock ) (struct omap_dss_device*) ;} ;
struct TYPE_6__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dsicm_framedone_cb ; 
 int dsicm_set_update_window (struct panel_drv_data*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int dsicm_wake_up (struct panel_drv_data*) ; 
 scalar_t__ gpio_is_valid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  schedule_delayed_work (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct omap_dss_device*) ; 
 int stub2 (struct omap_dss_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct panel_drv_data*) ; 
 int /*<<< orphan*/  stub3 (struct omap_dss_device*) ; 
 struct panel_drv_data* to_panel_data (struct omap_dss_device*) ; 

__attribute__((used)) static int dsicm_update(struct omap_dss_device *dssdev,
				    u16 x, u16 y, u16 w, u16 h)
{
	struct panel_drv_data *ddata = to_panel_data(dssdev);
	struct omap_dss_device *in = ddata->in;
	int r;

	dev_dbg(&ddata->pdev->dev, "update %d, %d, %d x %d\n", x, y, w, h);

	mutex_lock(&ddata->lock);
	in->ops.dsi->bus_lock(in);

	r = dsicm_wake_up(ddata);
	if (r)
		goto err;

	if (!ddata->enabled) {
		r = 0;
		goto err;
	}

	/* XXX no need to send this every frame, but dsi break if not done */
	r = dsicm_set_update_window(ddata, 0, 0,
			dssdev->panel.timings.x_res,
			dssdev->panel.timings.y_res);
	if (r)
		goto err;

	if (ddata->te_enabled && gpio_is_valid(ddata->ext_te_gpio)) {
		schedule_delayed_work(&ddata->te_timeout_work,
				msecs_to_jiffies(250));
		atomic_set(&ddata->do_update, 1);
	} else {
		r = in->ops.dsi->update(in, ddata->channel, dsicm_framedone_cb,
				ddata);
		if (r)
			goto err;
	}

	/* note: no bus_unlock here. unlock is in framedone_cb */
	mutex_unlock(&ddata->lock);
	return 0;
err:
	in->ops.dsi->bus_unlock(in);
	mutex_unlock(&ddata->lock);
	return r;
}