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
typedef  int /*<<< orphan*/  ext2_u32_list ;
typedef  scalar_t__ ext2_badblocks_list ;
typedef  scalar_t__ blk_t ;
typedef  int /*<<< orphan*/  __u32 ;

/* Variables and functions */
 int ext2fs_u32_list_test (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int ext2fs_badblocks_list_test(ext2_badblocks_list bb, blk_t blk)
{
	return ext2fs_u32_list_test((ext2_u32_list) bb, (__u32) blk);
}