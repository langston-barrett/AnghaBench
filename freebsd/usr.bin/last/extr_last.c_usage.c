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
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  xo_error (char*) ; 

__attribute__((used)) static void
usage(void)
{
	xo_error(
"usage: last [-swy] [-d [[CC]YY][MMDD]hhmm[.SS]] [-f file] [-h host]\n"
"            [-n maxrec] [-t tty] [user ...]\n");
	exit(1);
}