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
struct g_raid3_event {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  M_RAID3 ; 
 int /*<<< orphan*/  free (struct g_raid3_event*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
g_raid3_event_free(struct g_raid3_event *ep)
{

	free(ep, M_RAID3);
}