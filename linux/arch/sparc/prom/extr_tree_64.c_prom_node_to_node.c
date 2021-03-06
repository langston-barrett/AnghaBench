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
typedef  scalar_t__ phandle ;

/* Variables and functions */
 int /*<<< orphan*/  p1275_cmd_direct (unsigned long*) ; 

__attribute__((used)) static phandle prom_node_to_node(const char *type, phandle node)
{
	unsigned long args[5];

	args[0] = (unsigned long) type;
	args[1] = 1;
	args[2] = 1;
	args[3] = (unsigned int) node;
	args[4] = (unsigned long) -1;

	p1275_cmd_direct(args);

	return (phandle) args[4];
}