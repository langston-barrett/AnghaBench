#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  th_tid; TYPE_2__* th_ta; } ;
typedef  TYPE_1__ td_thrhandle_t ;
struct TYPE_6__ {int /*<<< orphan*/  ph; } ;
typedef  TYPE_2__ td_thragent_t ;
typedef  int td_err_e ;
typedef  int /*<<< orphan*/  prgregset_t ;

/* Variables and functions */
 int P2T (int) ; 
 int /*<<< orphan*/  TDBG_FUNC () ; 
 int ps_lgetregs (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int pt_validate (TYPE_1__ const*) ; 

__attribute__((used)) static td_err_e
pt_thr_getgregs(const td_thrhandle_t *th, prgregset_t gregs)
{
	const td_thragent_t *ta = th->th_ta;
	int ret;

	TDBG_FUNC();

	ret = pt_validate(th);
	if (ret)
		return (ret);

	ret = ps_lgetregs(ta->ph, th->th_tid, gregs);
	return (P2T(ret));
}