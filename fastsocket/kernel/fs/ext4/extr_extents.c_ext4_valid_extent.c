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
struct inode {int /*<<< orphan*/  i_sb; } ;
struct ext4_extent {int dummy; } ;
typedef  int /*<<< orphan*/  ext4_fsblk_t ;

/* Variables and functions */
 int /*<<< orphan*/  EXT4_SB (int /*<<< orphan*/ ) ; 
 int ext4_data_block_valid (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int ext4_ext_get_actual_len (struct ext4_extent*) ; 
 int /*<<< orphan*/  ext4_ext_pblock (struct ext4_extent*) ; 

__attribute__((used)) static int ext4_valid_extent(struct inode *inode, struct ext4_extent *ext)
{
	ext4_fsblk_t block = ext4_ext_pblock(ext);
	int len = ext4_ext_get_actual_len(ext);

	if (len == 0)
		return 0;
	return ext4_data_block_valid(EXT4_SB(inode->i_sb), block, len);
}