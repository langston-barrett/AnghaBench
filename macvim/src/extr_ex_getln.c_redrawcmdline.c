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
 int /*<<< orphan*/  FALSE ; 
 scalar_t__ cmd_silent ; 
 int /*<<< orphan*/  compute_cmdrow () ; 
 int /*<<< orphan*/  cursorcmd () ; 
 int /*<<< orphan*/  need_wait_return ; 
 int /*<<< orphan*/  redrawcmd () ; 

void
redrawcmdline()
{
    if (cmd_silent)
	return;
    need_wait_return = FALSE;
    compute_cmdrow();
    redrawcmd();
    cursorcmd();
}