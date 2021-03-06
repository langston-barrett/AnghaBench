#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u64 ;
struct TYPE_5__ {int msr_val; scalar_t__ accum_steal; scalar_t__ last_steal; } ;
struct TYPE_6__ {TYPE_1__ st; } ;
struct kvm_vcpu {TYPE_2__ arch; } ;
struct TYPE_7__ {scalar_t__ run_delay; } ;
struct TYPE_8__ {TYPE_3__ sched_info; } ;

/* Variables and functions */
 int KVM_MSR_ENABLED ; 
 TYPE_4__* current ; 

__attribute__((used)) static void accumulate_steal_time(struct kvm_vcpu *vcpu)
{
	u64 delta;

	if (!(vcpu->arch.st.msr_val & KVM_MSR_ENABLED))
		return;

	delta = current->sched_info.run_delay - vcpu->arch.st.last_steal;
	vcpu->arch.st.last_steal = current->sched_info.run_delay;
	vcpu->arch.st.accum_steal = delta;
}