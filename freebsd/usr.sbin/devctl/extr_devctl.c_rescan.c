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

/* Variables and functions */
 scalar_t__ devctl_rescan (char*) ; 
 int /*<<< orphan*/  err (int,char*,char*) ; 
 int /*<<< orphan*/  usage () ; 

__attribute__((used)) static int
rescan(int ac, char **av)
{

	if (ac != 2)
		usage();
	if (devctl_rescan(av[1]) < 0)
		err(1, "Failed to rescan %s", av[1]);
	return (0);
}