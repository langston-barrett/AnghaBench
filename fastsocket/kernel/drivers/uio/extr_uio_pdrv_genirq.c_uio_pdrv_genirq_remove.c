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
struct uio_pdrv_genirq_platdata {int /*<<< orphan*/  uioinfo; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct uio_pdrv_genirq_platdata*) ; 
 struct uio_pdrv_genirq_platdata* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  pm_runtime_disable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uio_unregister_device (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int uio_pdrv_genirq_remove(struct platform_device *pdev)
{
	struct uio_pdrv_genirq_platdata *priv = platform_get_drvdata(pdev);

	uio_unregister_device(priv->uioinfo);
	pm_runtime_disable(&pdev->dev);
	kfree(priv);
	return 0;
}