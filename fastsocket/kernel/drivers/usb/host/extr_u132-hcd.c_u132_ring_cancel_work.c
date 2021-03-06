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
struct u132_ring {int /*<<< orphan*/  scheduler; } ;
struct u132 {int /*<<< orphan*/  kref; } ;

/* Variables and functions */
 scalar_t__ cancel_delayed_work (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  u132_hcd_delete ; 

__attribute__((used)) static void u132_ring_cancel_work(struct u132 *u132, struct u132_ring *ring)
{
	if (cancel_delayed_work(&ring->scheduler))
		kref_put(&u132->kref, u132_hcd_delete);
}