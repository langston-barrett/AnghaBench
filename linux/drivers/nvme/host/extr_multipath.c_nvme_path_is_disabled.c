#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct nvme_ns {int /*<<< orphan*/  flags; TYPE_1__* ctrl; } ;
struct TYPE_2__ {scalar_t__ state; } ;

/* Variables and functions */
 scalar_t__ NVME_CTRL_LIVE ; 
 int /*<<< orphan*/  NVME_NS_ANA_PENDING ; 
 int /*<<< orphan*/  NVME_NS_REMOVING ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static bool nvme_path_is_disabled(struct nvme_ns *ns)
{
	return ns->ctrl->state != NVME_CTRL_LIVE ||
		test_bit(NVME_NS_ANA_PENDING, &ns->flags) ||
		test_bit(NVME_NS_REMOVING, &ns->flags);
}