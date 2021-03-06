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
typedef  int u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct vgic_register_region {int dummy; } ;
struct vgic_reg_attr {int addr; struct kvm_vcpu* vcpu; } ;
struct vgic_io_device {int /*<<< orphan*/  base_addr; void* nr_regions; void* regions; } ;
struct kvm_vcpu {int dummy; } ;
struct kvm_device_attr {int group; int attr; } ;
struct kvm_device {int dummy; } ;
typedef  int gpa_t ;

/* Variables and functions */
 void* ARRAY_SIZE (void*) ; 
 int ENXIO ; 
#define  KVM_DEV_ARM_VGIC_GRP_CPU_SYSREGS 130 
#define  KVM_DEV_ARM_VGIC_GRP_DIST_REGS 129 
#define  KVM_DEV_ARM_VGIC_GRP_REDIST_REGS 128 
 int KVM_DEV_ARM_VGIC_SYSREG_INSTR_MASK ; 
 struct vgic_register_region* vgic_get_mmio_region (struct kvm_vcpu*,struct vgic_io_device*,int,int) ; 
 void* vgic_v3_dist_registers ; 
 int vgic_v3_has_cpu_sysregs_attr (struct kvm_vcpu*,int /*<<< orphan*/ ,int,int*) ; 
 int vgic_v3_parse_attr (struct kvm_device*,struct kvm_device_attr*,struct vgic_reg_attr*) ; 
 void* vgic_v3_rd_registers ; 

int vgic_v3_has_attr_regs(struct kvm_device *dev, struct kvm_device_attr *attr)
{
	const struct vgic_register_region *region;
	struct vgic_io_device iodev;
	struct vgic_reg_attr reg_attr;
	struct kvm_vcpu *vcpu;
	gpa_t addr;
	int ret;

	ret = vgic_v3_parse_attr(dev, attr, &reg_attr);
	if (ret)
		return ret;

	vcpu = reg_attr.vcpu;
	addr = reg_attr.addr;

	switch (attr->group) {
	case KVM_DEV_ARM_VGIC_GRP_DIST_REGS:
		iodev.regions = vgic_v3_dist_registers;
		iodev.nr_regions = ARRAY_SIZE(vgic_v3_dist_registers);
		iodev.base_addr = 0;
		break;
	case KVM_DEV_ARM_VGIC_GRP_REDIST_REGS:{
		iodev.regions = vgic_v3_rd_registers;
		iodev.nr_regions = ARRAY_SIZE(vgic_v3_rd_registers);
		iodev.base_addr = 0;
		break;
	}
	case KVM_DEV_ARM_VGIC_GRP_CPU_SYSREGS: {
		u64 reg, id;

		id = (attr->attr & KVM_DEV_ARM_VGIC_SYSREG_INSTR_MASK);
		return vgic_v3_has_cpu_sysregs_attr(vcpu, 0, id, &reg);
	}
	default:
		return -ENXIO;
	}

	/* We only support aligned 32-bit accesses. */
	if (addr & 3)
		return -ENXIO;

	region = vgic_get_mmio_region(vcpu, &iodev, addr, sizeof(u32));
	if (!region)
		return -ENXIO;

	return 0;
}