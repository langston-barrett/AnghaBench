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
 int /*<<< orphan*/ * cont ; 
 int /*<<< orphan*/  redo_fd_request ; 
 int /*<<< orphan*/  rw_cont ; 
 int /*<<< orphan*/  schedule_bh (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void process_fd_request(void)
{
	cont = &rw_cont;
	schedule_bh(redo_fd_request);
}