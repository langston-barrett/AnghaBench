#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {TYPE_2__* vr; } ;
struct c4iw_rdev {TYPE_3__ lldi; } ;
struct TYPE_4__ {int size; } ;
struct TYPE_5__ {TYPE_1__ stag; } ;

/* Variables and functions */
 scalar_t__ T4_MAX_NUM_STAG ; 
 int min (int,int) ; 

__attribute__((used)) static inline int c4iw_num_stags(struct c4iw_rdev *rdev)
{
	return min((int)T4_MAX_NUM_STAG, (int)(rdev->lldi.vr->stag.size >> 5));
}