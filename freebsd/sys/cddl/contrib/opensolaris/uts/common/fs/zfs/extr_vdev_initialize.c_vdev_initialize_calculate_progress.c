#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_5__ ;
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
struct TYPE_16__ {scalar_t__ vdev_leaf_zap; size_t vdev_initialize_bytes_est; size_t vdev_initialize_bytes_done; scalar_t__ vdev_initialize_last_offset; TYPE_1__* vdev_top; int /*<<< orphan*/  vdev_spa; } ;
typedef  TYPE_3__ vdev_t ;
typedef  size_t uint64_t ;
struct TYPE_17__ {scalar_t__ rs_start; scalar_t__ rs_end; } ;
typedef  TYPE_4__ range_seg_t ;
struct TYPE_18__ {size_t ms_size; scalar_t__ ms_start; int /*<<< orphan*/  ms_lock; TYPE_2__* ms_allocatable; int /*<<< orphan*/  ms_sm; } ;
typedef  TYPE_5__ metaslab_t ;
struct TYPE_15__ {int /*<<< orphan*/  rt_root; } ;
struct TYPE_14__ {size_t vdev_ms_count; size_t vdev_children; int /*<<< orphan*/ * vdev_ops; TYPE_5__** vdev_ms; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 TYPE_4__* AVL_NEXT (int /*<<< orphan*/ *,TYPE_4__*) ; 
 int /*<<< orphan*/  RW_READER ; 
 int /*<<< orphan*/  RW_WRITER ; 
 int /*<<< orphan*/  SCL_CONFIG ; 
 int /*<<< orphan*/  VERIFY0 (int /*<<< orphan*/ ) ; 
 TYPE_4__* avl_first (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  metaslab_load (TYPE_5__*) ; 
 int /*<<< orphan*/  mutex_enter (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_exit (int /*<<< orphan*/ *) ; 
 scalar_t__ spa_config_held (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 size_t space_map_allocated (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vdev_raidz_ops ; 
 int /*<<< orphan*/  vdev_xlate (TYPE_3__*,TYPE_4__*,TYPE_4__*) ; 

__attribute__((used)) static void
vdev_initialize_calculate_progress(vdev_t *vd)
{
	ASSERT(spa_config_held(vd->vdev_spa, SCL_CONFIG, RW_READER) ||
	    spa_config_held(vd->vdev_spa, SCL_CONFIG, RW_WRITER));
	ASSERT(vd->vdev_leaf_zap != 0);

	vd->vdev_initialize_bytes_est = 0;
	vd->vdev_initialize_bytes_done = 0;

	for (uint64_t i = 0; i < vd->vdev_top->vdev_ms_count; i++) {
		metaslab_t *msp = vd->vdev_top->vdev_ms[i];
		mutex_enter(&msp->ms_lock);

		uint64_t ms_free = msp->ms_size -
		    space_map_allocated(msp->ms_sm);

		if (vd->vdev_top->vdev_ops == &vdev_raidz_ops)
			ms_free /= vd->vdev_top->vdev_children;

		/*
		 * Convert the metaslab range to a physical range
		 * on our vdev. We use this to determine if we are
		 * in the middle of this metaslab range.
		 */
		range_seg_t logical_rs, physical_rs;
		logical_rs.rs_start = msp->ms_start;
		logical_rs.rs_end = msp->ms_start + msp->ms_size;
		vdev_xlate(vd, &logical_rs, &physical_rs);

		if (vd->vdev_initialize_last_offset <= physical_rs.rs_start) {
			vd->vdev_initialize_bytes_est += ms_free;
			mutex_exit(&msp->ms_lock);
			continue;
		} else if (vd->vdev_initialize_last_offset >
		    physical_rs.rs_end) {
			vd->vdev_initialize_bytes_done += ms_free;
			vd->vdev_initialize_bytes_est += ms_free;
			mutex_exit(&msp->ms_lock);
			continue;
		}

		/*
		 * If we get here, we're in the middle of initializing this
		 * metaslab. Load it and walk the free tree for more accurate
		 * progress estimation.
		 */
		VERIFY0(metaslab_load(msp));

		for (range_seg_t *rs = avl_first(&msp->ms_allocatable->rt_root);
		    rs; rs = AVL_NEXT(&msp->ms_allocatable->rt_root, rs)) {
			logical_rs.rs_start = rs->rs_start;
			logical_rs.rs_end = rs->rs_end;
			vdev_xlate(vd, &logical_rs, &physical_rs);

			uint64_t size = physical_rs.rs_end -
			    physical_rs.rs_start;
			vd->vdev_initialize_bytes_est += size;
			if (vd->vdev_initialize_last_offset >
			    physical_rs.rs_end) {
				vd->vdev_initialize_bytes_done += size;
			} else if (vd->vdev_initialize_last_offset >
			    physical_rs.rs_start &&
			    vd->vdev_initialize_last_offset <
			    physical_rs.rs_end) {
				vd->vdev_initialize_bytes_done +=
				    vd->vdev_initialize_last_offset -
				    physical_rs.rs_start;
			}
		}
		mutex_exit(&msp->ms_lock);
	}
}