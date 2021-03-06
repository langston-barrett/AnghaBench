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
struct TYPE_6__ {TYPE_2__* dentry; } ;
struct file {TYPE_3__ f_path; int /*<<< orphan*/  f_pos; } ;
typedef  int /*<<< orphan*/  loff_t ;
struct TYPE_5__ {TYPE_1__* d_inode; } ;
struct TYPE_4__ {int /*<<< orphan*/  i_mutex; } ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  force_successful_syscall_return () ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static loff_t memory_lseek(struct file * file, loff_t offset, int orig)
{
	loff_t ret;

	mutex_lock(&file->f_path.dentry->d_inode->i_mutex);
	switch (orig) {
		case 0:
			file->f_pos = offset;
			ret = file->f_pos;
			force_successful_syscall_return();
			break;
		case 1:
			file->f_pos += offset;
			ret = file->f_pos;
			force_successful_syscall_return();
			break;
		default:
			ret = -EINVAL;
	}
	mutex_unlock(&file->f_path.dentry->d_inode->i_mutex);
	return ret;
}