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
typedef  int /*<<< orphan*/  u32 ;
struct adapter {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  A_TP_RSS_LKP_TABLE ; 
 int /*<<< orphan*/  F_LKPTBLROWVLD ; 
 int t4_wait_op_done_val (struct adapter*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  t4_write_reg (struct adapter*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int rd_rss_row(struct adapter *adap, int row, u32 *val)
{
	t4_write_reg(adap, A_TP_RSS_LKP_TABLE, 0xfff00000 | row);
	return t4_wait_op_done_val(adap, A_TP_RSS_LKP_TABLE, F_LKPTBLROWVLD, 1,
				   5, 0, val);
}