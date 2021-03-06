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
typedef  int /*<<< orphan*/  u16 ;
struct gfs2_sbd {int /*<<< orphan*/  sd_fsname; } ;
struct buffer_head {scalar_t__ b_blocknr; } ;

/* Variables and functions */
 int gfs2_lm_withdraw (struct gfs2_sbd*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned long long,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,char*,unsigned int) ; 

int gfs2_metatype_check_ii(struct gfs2_sbd *sdp, struct buffer_head *bh,
			   u16 type, u16 t, const char *function,
			   char *file, unsigned int line)
{
	int me;
	me = gfs2_lm_withdraw(sdp,
		"GFS2: fsid=%s: fatal: invalid metadata block\n"
		"GFS2: fsid=%s:   bh = %llu (type: exp=%u, found=%u)\n"
		"GFS2: fsid=%s:   function = %s, file = %s, line = %u\n",
		sdp->sd_fsname,
		sdp->sd_fsname, (unsigned long long)bh->b_blocknr, type, t,
		sdp->sd_fsname, function, file, line);
	return (me) ? -1 : -2;
}