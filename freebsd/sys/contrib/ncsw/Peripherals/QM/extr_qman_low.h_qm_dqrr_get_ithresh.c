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
typedef  int /*<<< orphan*/  uint8_t ;
struct qm_dqrr {int /*<<< orphan*/  ithresh; } ;
struct qm_portal {struct qm_dqrr dqrr; } ;

/* Variables and functions */

__attribute__((used)) static __inline__ uint8_t qm_dqrr_get_ithresh(struct qm_portal *portal)
{
    register struct qm_dqrr *dqrr = &portal->dqrr;
    return dqrr->ithresh;
}