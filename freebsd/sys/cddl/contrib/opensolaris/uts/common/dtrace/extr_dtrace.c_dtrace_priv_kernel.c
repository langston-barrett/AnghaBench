#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_4__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int dcr_action; } ;
struct TYPE_6__ {TYPE_1__ dts_cred; } ;
typedef  TYPE_2__ dtrace_state_t ;
struct TYPE_7__ {int /*<<< orphan*/  cpuc_dtrace_flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  CPU_DTRACE_KPRIV ; 
 int DTRACE_CRA_KERNEL ; 
 TYPE_4__* cpu_core ; 
 size_t curcpu ; 

__attribute__((used)) static int
dtrace_priv_kernel(dtrace_state_t *state)
{
	if (state->dts_cred.dcr_action & DTRACE_CRA_KERNEL)
		return (1);

	cpu_core[curcpu].cpuc_dtrace_flags |= CPU_DTRACE_KPRIV;

	return (0);
}