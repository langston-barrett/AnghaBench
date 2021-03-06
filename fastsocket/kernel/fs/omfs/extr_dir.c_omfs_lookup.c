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
struct TYPE_3__ {int /*<<< orphan*/  h_self; } ;
struct omfs_inode {TYPE_1__ i_head; } ;
struct nameidata {int dummy; } ;
struct inode {int /*<<< orphan*/  i_sb; scalar_t__ b_data; } ;
struct TYPE_4__ {scalar_t__ len; int /*<<< orphan*/  name; } ;
struct dentry {TYPE_2__ d_name; } ;
struct buffer_head {int /*<<< orphan*/  i_sb; scalar_t__ b_data; } ;
typedef  int /*<<< orphan*/  ino_t ;

/* Variables and functions */
 int /*<<< orphan*/  ENAMETOOLONG ; 
 struct dentry* ERR_CAST (struct inode*) ; 
 struct dentry* ERR_PTR (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (struct inode*) ; 
 scalar_t__ OMFS_NAMELEN ; 
 int /*<<< orphan*/  be64_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  brelse (struct inode*) ; 
 int /*<<< orphan*/  d_add (struct dentry*,struct inode*) ; 
 struct inode* omfs_find_entry (struct inode*,int /*<<< orphan*/ ,scalar_t__) ; 
 struct inode* omfs_iget (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct dentry *omfs_lookup(struct inode *dir, struct dentry *dentry,
				  struct nameidata *nd)
{
	struct buffer_head *bh;
	struct inode *inode = NULL;

	if (dentry->d_name.len > OMFS_NAMELEN)
		return ERR_PTR(-ENAMETOOLONG);

	bh = omfs_find_entry(dir, dentry->d_name.name, dentry->d_name.len);
	if (!IS_ERR(bh)) {
		struct omfs_inode *oi = (struct omfs_inode *)bh->b_data;
		ino_t ino = be64_to_cpu(oi->i_head.h_self);
		brelse(bh);
		inode = omfs_iget(dir->i_sb, ino);
		if (IS_ERR(inode))
			return ERR_CAST(inode);
	}
	d_add(dentry, inode);
	return NULL;
}