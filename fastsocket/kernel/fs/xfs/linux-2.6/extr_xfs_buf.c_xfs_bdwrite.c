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
struct xfs_buf {int b_flags; } ;

/* Variables and functions */
 int XBF_ASYNC ; 
 int XBF_DELWRI ; 
 int XBF_READ ; 
 int /*<<< orphan*/  _RET_IP_ ; 
 int /*<<< orphan*/  trace_xfs_buf_bdwrite (struct xfs_buf*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xfs_buf_delwri_queue (struct xfs_buf*,int) ; 

void
xfs_bdwrite(
	void			*mp,
	struct xfs_buf		*bp)
{
	trace_xfs_buf_bdwrite(bp, _RET_IP_);

	bp->b_flags &= ~XBF_READ;
	bp->b_flags |= (XBF_DELWRI | XBF_ASYNC);

	xfs_buf_delwri_queue(bp, 1);
}