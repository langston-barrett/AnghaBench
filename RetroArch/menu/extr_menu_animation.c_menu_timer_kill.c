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
typedef  int /*<<< orphan*/  menu_timer_t ;
typedef  uintptr_t menu_animation_ctx_tag ;

/* Variables and functions */
 int /*<<< orphan*/  menu_animation_kill_by_tag (uintptr_t*) ; 

void menu_timer_kill(menu_timer_t *timer)
{
   menu_animation_ctx_tag tag = (uintptr_t) timer;
   menu_animation_kill_by_tag(&tag);
}