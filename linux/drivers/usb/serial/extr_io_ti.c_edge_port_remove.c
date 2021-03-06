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
struct usb_serial_port {int dummy; } ;
struct edgeport_port {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  edge_remove_sysfs_attrs (struct usb_serial_port*) ; 
 int /*<<< orphan*/  kfree (struct edgeport_port*) ; 
 struct edgeport_port* usb_get_serial_port_data (struct usb_serial_port*) ; 

__attribute__((used)) static int edge_port_remove(struct usb_serial_port *port)
{
	struct edgeport_port *edge_port;

	edge_port = usb_get_serial_port_data(port);
	edge_remove_sysfs_attrs(port);
	kfree(edge_port);

	return 0;
}