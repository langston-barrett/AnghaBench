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
typedef  int /*<<< orphan*/  nvlist_t ;

/* Variables and functions */
 int /*<<< orphan*/  ZFS_IOC_GET_BOOKMARK_PROPS ; 
 int /*<<< orphan*/ * fnvlist_alloc () ; 
 int /*<<< orphan*/  fnvlist_free (int /*<<< orphan*/ *) ; 
 int lzc_ioctl (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ **) ; 

int
lzc_get_bookmark_props(const char *bookmark, nvlist_t **props)
{
	int error;

	nvlist_t *innvl = fnvlist_alloc();
	error = lzc_ioctl(ZFS_IOC_GET_BOOKMARK_PROPS, bookmark, innvl, props);
	fnvlist_free(innvl);

	return (error);
}