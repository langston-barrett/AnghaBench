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
struct bfa_iocpf {int /*<<< orphan*/  ioc; } ;

/* Variables and functions */
 int /*<<< orphan*/  bfa_ioc_hw_sem_get (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfa_ioc_hw_sem_init (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
bfa_iocpf_sm_fwcheck_entry(struct bfa_iocpf *iocpf)
{
	bfa_ioc_hw_sem_init(iocpf->ioc);
	bfa_ioc_hw_sem_get(iocpf->ioc);
}