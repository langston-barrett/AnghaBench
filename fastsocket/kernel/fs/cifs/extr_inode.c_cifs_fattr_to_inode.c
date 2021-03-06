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
struct inode {int i_state; int i_blocks; int /*<<< orphan*/  i_flags; int /*<<< orphan*/  i_lock; int /*<<< orphan*/  i_mode; int /*<<< orphan*/  i_gid; int /*<<< orphan*/  i_uid; int /*<<< orphan*/  i_nlink; int /*<<< orphan*/  i_rdev; int /*<<< orphan*/  i_ctime; int /*<<< orphan*/  i_mtime; int /*<<< orphan*/  i_atime; int /*<<< orphan*/  i_sb; } ;
struct cifs_sb_info {int mnt_cifs_flags; } ;
struct cifs_fattr {int cf_flags; int cf_bytes; int /*<<< orphan*/  cf_eof; int /*<<< orphan*/  cf_cifsattrs; int /*<<< orphan*/  cf_mode; int /*<<< orphan*/  cf_gid; int /*<<< orphan*/  cf_uid; int /*<<< orphan*/  cf_nlink; int /*<<< orphan*/  cf_rdev; int /*<<< orphan*/  cf_ctime; int /*<<< orphan*/  cf_mtime; int /*<<< orphan*/  cf_atime; } ;
struct cifsInodeInfo {unsigned long time; int delete_pending; int /*<<< orphan*/  server_eof; int /*<<< orphan*/  cifsAttrs; } ;

/* Variables and functions */
 int CIFS_FATTR_DELETE_PENDING ; 
 int CIFS_FATTR_DFS_REFERRAL ; 
 int CIFS_FATTR_NEED_REVAL ; 
 struct cifsInodeInfo* CIFS_I (struct inode*) ; 
 int CIFS_MOUNT_DYNPERM ; 
 struct cifs_sb_info* CIFS_SB (int /*<<< orphan*/ ) ; 
 int I_NEW ; 
 int /*<<< orphan*/  S_AUTOMOUNT ; 
 int /*<<< orphan*/  cFYI (int,char*,struct inode*,unsigned long,unsigned long) ; 
 int /*<<< orphan*/  cifs_revalidate_cache (struct inode*,struct cifs_fattr*) ; 
 int /*<<< orphan*/  cifs_set_ops (struct inode*) ; 
 int /*<<< orphan*/  i_size_write (struct inode*,int /*<<< orphan*/ ) ; 
 scalar_t__ is_size_safe_to_change (struct cifsInodeInfo*,int /*<<< orphan*/ ) ; 
 unsigned long jiffies ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

void
cifs_fattr_to_inode(struct inode *inode, struct cifs_fattr *fattr)
{
	struct cifsInodeInfo *cifs_i = CIFS_I(inode);
	struct cifs_sb_info *cifs_sb = CIFS_SB(inode->i_sb);
	unsigned long oldtime = cifs_i->time;

	cifs_revalidate_cache(inode, fattr);

	inode->i_atime = fattr->cf_atime;
	inode->i_mtime = fattr->cf_mtime;
	inode->i_ctime = fattr->cf_ctime;
	inode->i_rdev = fattr->cf_rdev;
	inode->i_nlink = fattr->cf_nlink;
	inode->i_uid = fattr->cf_uid;
	inode->i_gid = fattr->cf_gid;

	/* if dynperm is set, don't clobber existing mode */
	if (inode->i_state & I_NEW ||
	    !(cifs_sb->mnt_cifs_flags & CIFS_MOUNT_DYNPERM))
		inode->i_mode = fattr->cf_mode;

	cifs_i->cifsAttrs = fattr->cf_cifsattrs;

	if (fattr->cf_flags & CIFS_FATTR_NEED_REVAL)
		cifs_i->time = 0;
	else
		cifs_i->time = jiffies;

	cFYI(1, "inode 0x%p old_time=%ld new_time=%ld", inode,
		 oldtime, cifs_i->time);

	cifs_i->delete_pending = fattr->cf_flags & CIFS_FATTR_DELETE_PENDING;

	cifs_i->server_eof = fattr->cf_eof;
	/*
	 * Can't safely change the file size here if the client is writing to
	 * it due to potential races.
	 */
	spin_lock(&inode->i_lock);
	if (is_size_safe_to_change(cifs_i, fattr->cf_eof)) {
		i_size_write(inode, fattr->cf_eof);

		/*
		 * i_blocks is not related to (i_size / i_blksize),
		 * but instead 512 byte (2**9) size is required for
		 * calculating num blocks.
		 */
		inode->i_blocks = (512 - 1 + fattr->cf_bytes) >> 9;
	}
	spin_unlock(&inode->i_lock);

	if (fattr->cf_flags & CIFS_FATTR_DFS_REFERRAL)
		inode->i_flags |= S_AUTOMOUNT;
	cifs_set_ops(inode);
}