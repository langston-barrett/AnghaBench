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
typedef  int /*<<< orphan*/  uint32_t ;
struct qm_addr {int /*<<< orphan*/  addr_ci; } ;

/* Variables and functions */
 int /*<<< orphan*/  GET_UINT32 (int /*<<< orphan*/ ) ; 
 scalar_t__ ptr_ADD (int /*<<< orphan*/ ,uintptr_t) ; 

__attribute__((used)) static __inline__ uint32_t __qm_in(struct qm_addr *qm, uintptr_t offset)
{
    uint32_t    *tmp = (uint32_t *)ptr_ADD(qm->addr_ci, offset);
    return GET_UINT32(*tmp);
}