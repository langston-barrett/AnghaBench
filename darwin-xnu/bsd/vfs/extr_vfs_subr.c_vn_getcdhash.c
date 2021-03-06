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
struct vnode {int dummy; } ;
typedef  int /*<<< orphan*/  off_t ;

/* Variables and functions */
 int ubc_cs_getcdhash (struct vnode*,int /*<<< orphan*/ ,unsigned char*) ; 

int
vn_getcdhash(struct vnode *vp, off_t offset, unsigned char *cdhash)
{
	return ubc_cs_getcdhash(vp, offset, cdhash);
}