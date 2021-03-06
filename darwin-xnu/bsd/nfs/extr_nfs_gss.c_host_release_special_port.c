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
typedef  int /*<<< orphan*/  mach_port_t ;

/* Variables and functions */
 scalar_t__ IPC_PORT_VALID (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ipc_port_release_send (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
host_release_special_port(mach_port_t mp)
{
	if (IPC_PORT_VALID(mp))
		ipc_port_release_send(mp);
}