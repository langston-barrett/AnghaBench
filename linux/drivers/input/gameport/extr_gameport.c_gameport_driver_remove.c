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
struct gameport_driver {int /*<<< orphan*/  (* disconnect ) (struct gameport*) ;} ;
struct gameport {int dummy; } ;
struct device {int /*<<< orphan*/  driver; } ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct gameport*) ; 
 struct gameport_driver* to_gameport_driver (int /*<<< orphan*/ ) ; 
 struct gameport* to_gameport_port (struct device*) ; 

__attribute__((used)) static int gameport_driver_remove(struct device *dev)
{
	struct gameport *gameport = to_gameport_port(dev);
	struct gameport_driver *drv = to_gameport_driver(dev->driver);

	drv->disconnect(gameport);
	return 0;
}