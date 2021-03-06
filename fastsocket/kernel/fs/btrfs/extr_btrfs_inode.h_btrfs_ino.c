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
typedef  scalar_t__ u64 ;
struct inode {scalar_t__ i_ino; } ;
struct TYPE_3__ {scalar_t__ type; scalar_t__ objectid; } ;
struct TYPE_4__ {TYPE_1__ location; } ;

/* Variables and functions */
 TYPE_2__* BTRFS_I (struct inode*) ; 
 scalar_t__ BTRFS_ROOT_ITEM_KEY ; 

__attribute__((used)) static inline u64 btrfs_ino(struct inode *inode)
{
	u64 ino = BTRFS_I(inode)->location.objectid;

	/*
	 * !ino: btree_inode
	 * type == BTRFS_ROOT_ITEM_KEY: subvol dir
	 */
	if (!ino || BTRFS_I(inode)->location.type == BTRFS_ROOT_ITEM_KEY)
		ino = inode->i_ino;
	return ino;
}