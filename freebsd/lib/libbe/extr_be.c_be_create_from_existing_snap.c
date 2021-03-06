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
typedef  int /*<<< orphan*/  libbe_handle_t ;

/* Variables and functions */
 int be_clone (int /*<<< orphan*/ *,char const*,char const*,int) ; 

int
be_create_from_existing_snap(libbe_handle_t *lbh, const char *bename,
    const char *snap)
{
	return (be_clone(lbh, bename, snap, -1));
}