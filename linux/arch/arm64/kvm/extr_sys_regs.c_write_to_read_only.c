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
struct sys_reg_params {int dummy; } ;
struct sys_reg_desc {int dummy; } ;
struct kvm_vcpu {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  WARN_ONCE (int,char*) ; 
 int /*<<< orphan*/  kvm_inject_undefined (struct kvm_vcpu*) ; 
 int /*<<< orphan*/  print_sys_reg_instr (struct sys_reg_params*) ; 

__attribute__((used)) static bool write_to_read_only(struct kvm_vcpu *vcpu,
			       struct sys_reg_params *params,
			       const struct sys_reg_desc *r)
{
	WARN_ONCE(1, "Unexpected sys_reg write to read-only register\n");
	print_sys_reg_instr(params);
	kvm_inject_undefined(vcpu);
	return false;
}