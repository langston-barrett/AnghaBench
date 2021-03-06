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
struct ifacaddr6 {TYPE_2__* aca_rt; int /*<<< orphan*/  aca_idev; int /*<<< orphan*/  aca_refcnt; } ;
struct TYPE_3__ {int /*<<< orphan*/  dst; } ;
struct TYPE_4__ {TYPE_1__ u; } ;

/* Variables and functions */
 scalar_t__ atomic_dec_and_test (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dst_release (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  in6_dev_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct ifacaddr6*) ; 

__attribute__((used)) static void aca_put(struct ifacaddr6 *ac)
{
	if (atomic_dec_and_test(&ac->aca_refcnt)) {
		in6_dev_put(ac->aca_idev);
		dst_release(&ac->aca_rt->u.dst);
		kfree(ac);
	}
}