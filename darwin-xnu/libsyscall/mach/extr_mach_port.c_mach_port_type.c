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
typedef  int /*<<< orphan*/  mach_port_type_t ;
typedef  int /*<<< orphan*/  mach_port_name_t ;
typedef  int /*<<< orphan*/  kern_return_t ;
typedef  int /*<<< orphan*/  ipc_space_t ;

/* Variables and functions */
 int /*<<< orphan*/  _kernelrpc_mach_port_type (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

kern_return_t
mach_port_type(
	ipc_space_t task,
	mach_port_name_t name,
	mach_port_type_t *ptype)
{
	kern_return_t rv;

	rv = _kernelrpc_mach_port_type(task, name, ptype);

	return (rv);
}