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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int u32 ;
struct amdgpu_ring {TYPE_2__* adev; } ;
struct amdgpu_job {int dummy; } ;
struct amdgpu_ib {unsigned int length_dw; int flags; int gpu_addr; } ;
struct TYPE_3__ {int gds_compute_max_wave_id; } ;
struct TYPE_4__ {TYPE_1__ gds; } ;

/* Variables and functions */
 int AMDGPU_IB_FLAG_RESET_GDS_MAX_WAVE_ID ; 
 unsigned int AMDGPU_JOB_GET_VMID (struct amdgpu_job*) ; 
 unsigned int INDIRECT_BUFFER_VALID ; 
 int PACKET3 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  PACKET3_INDIRECT_BUFFER ; 
 int /*<<< orphan*/  PACKET3_SET_CONFIG_REG ; 
 int PACKET3_SET_CONFIG_REG_START ; 
 int /*<<< orphan*/  amdgpu_ring_write (struct amdgpu_ring*,int) ; 
 int mmGDS_COMPUTE_MAX_WAVE_ID ; 
 int upper_32_bits (int) ; 

__attribute__((used)) static void gfx_v8_0_ring_emit_ib_compute(struct amdgpu_ring *ring,
					  struct amdgpu_job *job,
					  struct amdgpu_ib *ib,
					  uint32_t flags)
{
	unsigned vmid = AMDGPU_JOB_GET_VMID(job);
	u32 control = INDIRECT_BUFFER_VALID | ib->length_dw | (vmid << 24);

	/* Currently, there is a high possibility to get wave ID mismatch
	 * between ME and GDS, leading to a hw deadlock, because ME generates
	 * different wave IDs than the GDS expects. This situation happens
	 * randomly when at least 5 compute pipes use GDS ordered append.
	 * The wave IDs generated by ME are also wrong after suspend/resume.
	 * Those are probably bugs somewhere else in the kernel driver.
	 *
	 * Writing GDS_COMPUTE_MAX_WAVE_ID resets wave ID counters in ME and
	 * GDS to 0 for this ring (me/pipe).
	 */
	if (ib->flags & AMDGPU_IB_FLAG_RESET_GDS_MAX_WAVE_ID) {
		amdgpu_ring_write(ring, PACKET3(PACKET3_SET_CONFIG_REG, 1));
		amdgpu_ring_write(ring, mmGDS_COMPUTE_MAX_WAVE_ID - PACKET3_SET_CONFIG_REG_START);
		amdgpu_ring_write(ring, ring->adev->gds.gds_compute_max_wave_id);
	}

	amdgpu_ring_write(ring, PACKET3(PACKET3_INDIRECT_BUFFER, 2));
	amdgpu_ring_write(ring,
#ifdef __BIG_ENDIAN
				(2 << 0) |
#endif
				(ib->gpu_addr & 0xFFFFFFFC));
	amdgpu_ring_write(ring, upper_32_bits(ib->gpu_addr) & 0xFFFF);
	amdgpu_ring_write(ring, control);
}