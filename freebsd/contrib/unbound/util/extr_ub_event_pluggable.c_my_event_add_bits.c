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
struct ub_event {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  ev_events; } ;
struct TYPE_4__ {TYPE_1__ ev; } ;

/* Variables and functions */
 TYPE_2__* AS_MY_EVENT (struct ub_event*) ; 
 int /*<<< orphan*/  NATIVE_BITS (short) ; 

__attribute__((used)) static void
my_event_add_bits(struct ub_event* ev, short bits)
{
	AS_MY_EVENT(ev)->ev.ev_events |= NATIVE_BITS(bits);
}