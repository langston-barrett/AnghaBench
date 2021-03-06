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
struct x86_exception {int dummy; } ;
struct TYPE_4__ {TYPE_1__* mmu; } ;
struct kvm_vcpu {TYPE_2__ arch; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* inject_page_fault ) (struct kvm_vcpu*,struct x86_exception*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct kvm_vcpu*,struct x86_exception*) ; 

__attribute__((used)) static void inject_page_fault(struct kvm_vcpu *vcpu,
			      struct x86_exception *fault)
{
	vcpu->arch.mmu->inject_page_fault(vcpu, fault);
}