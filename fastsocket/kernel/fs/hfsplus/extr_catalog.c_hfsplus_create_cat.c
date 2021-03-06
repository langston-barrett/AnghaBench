#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct super_block {int dummy; } ;
struct qstr {int /*<<< orphan*/  name; } ;
struct inode {int /*<<< orphan*/  i_ctime; int /*<<< orphan*/  i_mtime; int /*<<< orphan*/  i_size; int /*<<< orphan*/  i_ino; int /*<<< orphan*/  i_mode; struct super_block* i_sb; int /*<<< orphan*/  i_nlink; } ;
struct hfs_find_data {int /*<<< orphan*/  search_key; } ;
typedef  int /*<<< orphan*/  hfsplus_cat_entry ;
struct TYPE_2__ {int /*<<< orphan*/  cat_tree; } ;

/* Variables and functions */
 int /*<<< orphan*/  CURRENT_TIME_SEC ; 
 int /*<<< orphan*/  DBG_CAT_MOD ; 
 int EEXIST ; 
 int ENOENT ; 
 int /*<<< orphan*/  HFSPLUS_FILE_THREAD ; 
 int /*<<< orphan*/  HFSPLUS_FOLDER_THREAD ; 
 TYPE_1__ HFSPLUS_SB (struct super_block*) ; 
 scalar_t__ S_ISDIR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dprint (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int hfs_brec_find (struct hfs_find_data*) ; 
 int hfs_brec_insert (struct hfs_find_data*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  hfs_brec_remove (struct hfs_find_data*) ; 
 int /*<<< orphan*/  hfs_find_exit (struct hfs_find_data*) ; 
 int /*<<< orphan*/  hfs_find_init (int /*<<< orphan*/ ,struct hfs_find_data*) ; 
 int /*<<< orphan*/  hfsplus_cat_build_key (struct super_block*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct qstr*) ; 
 int hfsplus_cat_build_record (int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct inode*) ; 
 int hfsplus_fill_cat_thread (struct super_block*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct qstr*) ; 
 int /*<<< orphan*/  mark_inode_dirty (struct inode*) ; 

int hfsplus_create_cat(u32 cnid, struct inode *dir, struct qstr *str, struct inode *inode)
{
	struct hfs_find_data fd;
	struct super_block *sb;
	hfsplus_cat_entry entry;
	int entry_size;
	int err;

	dprint(DBG_CAT_MOD, "create_cat: %s,%u(%d)\n", str->name, cnid, inode->i_nlink);
	sb = dir->i_sb;
	hfs_find_init(HFSPLUS_SB(sb).cat_tree, &fd);

	hfsplus_cat_build_key(sb, fd.search_key, cnid, NULL);
	entry_size = hfsplus_fill_cat_thread(sb, &entry, S_ISDIR(inode->i_mode) ?
			HFSPLUS_FOLDER_THREAD : HFSPLUS_FILE_THREAD,
			dir->i_ino, str);
	err = hfs_brec_find(&fd);
	if (err != -ENOENT) {
		if (!err)
			err = -EEXIST;
		goto err2;
	}
	err = hfs_brec_insert(&fd, &entry, entry_size);
	if (err)
		goto err2;

	hfsplus_cat_build_key(sb, fd.search_key, dir->i_ino, str);
	entry_size = hfsplus_cat_build_record(&entry, cnid, inode);
	err = hfs_brec_find(&fd);
	if (err != -ENOENT) {
		/* panic? */
		if (!err)
			err = -EEXIST;
		goto err1;
	}
	err = hfs_brec_insert(&fd, &entry, entry_size);
	if (err)
		goto err1;

	dir->i_size++;
	dir->i_mtime = dir->i_ctime = CURRENT_TIME_SEC;
	mark_inode_dirty(dir);
	hfs_find_exit(&fd);
	return 0;

err1:
	hfsplus_cat_build_key(sb, fd.search_key, cnid, NULL);
	if (!hfs_brec_find(&fd))
		hfs_brec_remove(&fd);
err2:
	hfs_find_exit(&fd);
	return err;
}