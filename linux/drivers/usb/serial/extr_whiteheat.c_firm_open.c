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
struct whiteheat_simple {scalar_t__ port; } ;
struct usb_serial_port {scalar_t__ port_number; } ;
typedef  int /*<<< orphan*/  open_command ;
typedef  int /*<<< orphan*/  __u8 ;

/* Variables and functions */
 int /*<<< orphan*/  WHITEHEAT_OPEN ; 
 int firm_send_command (struct usb_serial_port*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int firm_open(struct usb_serial_port *port)
{
	struct whiteheat_simple open_command;

	open_command.port = port->port_number + 1;
	return firm_send_command(port, WHITEHEAT_OPEN,
		(__u8 *)&open_command, sizeof(open_command));
}