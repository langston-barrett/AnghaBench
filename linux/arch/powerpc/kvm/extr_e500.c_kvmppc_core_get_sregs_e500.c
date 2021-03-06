#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct kvmppc_vcpu_e500 {int /*<<< orphan*/  mcar; int /*<<< orphan*/  hid0; int /*<<< orphan*/  svr; } ;
struct TYPE_10__ {int /*<<< orphan*/ * ivor; } ;
struct kvm_vcpu {TYPE_5__ arch; } ;
struct TYPE_6__ {int /*<<< orphan*/  mcar; int /*<<< orphan*/  hid0; int /*<<< orphan*/  svr; scalar_t__ features; } ;
struct TYPE_7__ {TYPE_1__ fsl; } ;
struct TYPE_8__ {int features; int /*<<< orphan*/ * ivor_high; TYPE_2__ impl; int /*<<< orphan*/  impl_id; } ;
struct TYPE_9__ {TYPE_3__ e; } ;
struct kvm_sregs {TYPE_4__ u; } ;

/* Variables and functions */
 size_t BOOKE_IRQPRIO_PERFORMANCE_MONITOR ; 
 size_t BOOKE_IRQPRIO_SPE_FP_DATA ; 
 size_t BOOKE_IRQPRIO_SPE_FP_ROUND ; 
 size_t BOOKE_IRQPRIO_SPE_UNAVAIL ; 
 int KVM_SREGS_E_ARCH206_MMU ; 
 int /*<<< orphan*/  KVM_SREGS_E_IMPL_FSL ; 
 int KVM_SREGS_E_PM ; 
 int KVM_SREGS_E_SPE ; 
 int /*<<< orphan*/  kvmppc_get_sregs_e500_tlb (struct kvm_vcpu*,struct kvm_sregs*) ; 
 int /*<<< orphan*/  kvmppc_get_sregs_ivor (struct kvm_vcpu*,struct kvm_sregs*) ; 
 struct kvmppc_vcpu_e500* to_e500 (struct kvm_vcpu*) ; 

__attribute__((used)) static int kvmppc_core_get_sregs_e500(struct kvm_vcpu *vcpu,
				      struct kvm_sregs *sregs)
{
	struct kvmppc_vcpu_e500 *vcpu_e500 = to_e500(vcpu);

	sregs->u.e.features |= KVM_SREGS_E_ARCH206_MMU | KVM_SREGS_E_SPE |
	                       KVM_SREGS_E_PM;
	sregs->u.e.impl_id = KVM_SREGS_E_IMPL_FSL;

	sregs->u.e.impl.fsl.features = 0;
	sregs->u.e.impl.fsl.svr = vcpu_e500->svr;
	sregs->u.e.impl.fsl.hid0 = vcpu_e500->hid0;
	sregs->u.e.impl.fsl.mcar = vcpu_e500->mcar;

	sregs->u.e.ivor_high[0] = vcpu->arch.ivor[BOOKE_IRQPRIO_SPE_UNAVAIL];
	sregs->u.e.ivor_high[1] = vcpu->arch.ivor[BOOKE_IRQPRIO_SPE_FP_DATA];
	sregs->u.e.ivor_high[2] = vcpu->arch.ivor[BOOKE_IRQPRIO_SPE_FP_ROUND];
	sregs->u.e.ivor_high[3] =
		vcpu->arch.ivor[BOOKE_IRQPRIO_PERFORMANCE_MONITOR];

	kvmppc_get_sregs_ivor(vcpu, sregs);
	kvmppc_get_sregs_e500_tlb(vcpu, sregs);
	return 0;
}