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
struct jfs_ea {int namelen; } ;

/* Variables and functions */
 int XATTR_OS2_PREFIX_LEN ; 
 scalar_t__ is_os2_xattr (struct jfs_ea*) ; 

__attribute__((used)) static inline int name_size(struct jfs_ea *ea)
{
	if (is_os2_xattr(ea))
		return ea->namelen + XATTR_OS2_PREFIX_LEN;
	else
		return ea->namelen;
}