#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {TYPE_1__* watch; int /*<<< orphan*/  backup; } ;
typedef  TYPE_2__ phpdbg_watch_element ;
struct TYPE_4__ {int /*<<< orphan*/  backup; } ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 

void phpdbg_backup_watch_element(phpdbg_watch_element *element) {
	memcpy(&element->backup, &element->watch->backup, /* element->watch->size */ sizeof(element->backup));
}