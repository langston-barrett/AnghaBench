#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  sd_bus_message ;
struct TYPE_5__ {int /*<<< orphan*/  bus_track; } ;
typedef  TYPE_1__ Unit ;

/* Variables and functions */
 int /*<<< orphan*/  assert (TYPE_1__*) ; 
 int bus_unit_allocate_bus_track (TYPE_1__*) ; 
 int sd_bus_track_add_sender (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

int bus_unit_track_add_sender(Unit *u, sd_bus_message *m) {
        int r;

        assert(u);

        r = bus_unit_allocate_bus_track(u);
        if (r < 0)
                return r;

        return sd_bus_track_add_sender(u->bus_track, m);
}