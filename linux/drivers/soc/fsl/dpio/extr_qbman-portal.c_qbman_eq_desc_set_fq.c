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
typedef  int /*<<< orphan*/  u32 ;
struct qbman_eq_desc {int verb; int /*<<< orphan*/  tgtid; } ;

/* Variables and functions */
 int QB_ENQUEUE_CMD_TARGET_TYPE_SHIFT ; 
 int /*<<< orphan*/  cpu_to_le32 (int /*<<< orphan*/ ) ; 

void qbman_eq_desc_set_fq(struct qbman_eq_desc *d, u32 fqid)
{
	d->verb &= ~(1 << QB_ENQUEUE_CMD_TARGET_TYPE_SHIFT);
	d->tgtid = cpu_to_le32(fqid);
}