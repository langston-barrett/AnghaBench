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
struct bridge_if {int dummy; } ;

/* Variables and functions */
 struct bridge_if* bridge_first_bif () ; 
 int /*<<< orphan*/  bridge_list_age ; 
 struct bridge_if* bridge_next_bif (struct bridge_if*) ; 
 int /*<<< orphan*/  bridge_ports_update_listage () ; 
 int /*<<< orphan*/  bridge_update_bif (struct bridge_if*) ; 
 int /*<<< orphan*/  time (int /*<<< orphan*/ *) ; 

void
bridge_update_all_ifs(void)
{
	struct bridge_if *bif, *t_bif;

	for (bif = bridge_first_bif(); bif != NULL; bif = t_bif) {
		t_bif = bridge_next_bif(bif);
		bridge_update_bif(bif);
	}

	bridge_ports_update_listage();
	bridge_list_age = time(NULL);
}