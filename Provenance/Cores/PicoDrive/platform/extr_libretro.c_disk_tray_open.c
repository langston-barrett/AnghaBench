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
 int disk_ejected ; 
 int /*<<< orphan*/  lprintf (char*) ; 

__attribute__((used)) static void disk_tray_open(void)
{
	lprintf("cd tray open\n");
	disk_ejected = 1;
}