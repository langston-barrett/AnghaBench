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
struct retro_vfs_dir_handle {int dummy; } ;
struct RDIR {int dummy; } ;

/* Variables and functions */
 int dirent_readdir_cb (struct retro_vfs_dir_handle*) ; 
 int retro_vfs_readdir_impl (struct retro_vfs_dir_handle*) ; 

int retro_readdir(struct RDIR *rdir)
{
   if (dirent_readdir_cb != NULL)
      return dirent_readdir_cb((struct retro_vfs_dir_handle *)rdir);
   return retro_vfs_readdir_impl((struct retro_vfs_dir_handle *)rdir);
}