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
struct the_nilfs {int /*<<< orphan*/  ns_last_segment_lock; scalar_t__ ns_last_pseg; } ;
struct nilfs_segctor_attr {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
typedef  scalar_t__ sector_t ;

/* Variables and functions */
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  snprintf (char*,int /*<<< orphan*/ ,char*,unsigned long long) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static ssize_t
nilfs_segctor_last_pseg_block_show(struct nilfs_segctor_attr *attr,
				    struct the_nilfs *nilfs,
				    char *buf)
{
	sector_t last_pseg;

	spin_lock(&nilfs->ns_last_segment_lock);
	last_pseg = nilfs->ns_last_pseg;
	spin_unlock(&nilfs->ns_last_segment_lock);

	return snprintf(buf, PAGE_SIZE, "%llu\n",
			(unsigned long long)last_pseg);
}