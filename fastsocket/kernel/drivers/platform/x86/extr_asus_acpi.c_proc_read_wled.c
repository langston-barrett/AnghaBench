#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  off_t ;
struct TYPE_4__ {TYPE_1__* methods; } ;
struct TYPE_3__ {int /*<<< orphan*/  wled_status; } ;

/* Variables and functions */
 int /*<<< orphan*/  WLED_ON ; 
 TYPE_2__* hotk ; 
 int read_led (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int sprintf (char*,char*,int) ; 

__attribute__((used)) static int
proc_read_wled(char *page, char **start, off_t off, int count, int *eof,
	       void *data)
{
	return sprintf(page, "%d\n",
		       read_led(hotk->methods->wled_status, WLED_ON));
}