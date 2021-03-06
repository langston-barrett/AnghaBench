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
struct tty3270 {int dummy; } ;
struct raw3270_view {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  tty3270_free_screen (struct tty3270*) ; 
 int /*<<< orphan*/  tty3270_free_view (struct tty3270*) ; 

__attribute__((used)) static void
tty3270_free(struct raw3270_view *view)
{
	tty3270_free_screen((struct tty3270 *) view);
	tty3270_free_view((struct tty3270 *) view);
}