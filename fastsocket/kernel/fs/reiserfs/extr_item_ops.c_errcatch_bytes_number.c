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
struct item_head {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  reiserfs_warning (int /*<<< orphan*/ *,char*,char*) ; 

__attribute__((used)) static int errcatch_bytes_number(struct item_head *ih, int block_size)
{
	reiserfs_warning(NULL, "green-16001",
			 "Invalid item type observed, run fsck ASAP");
	return 0;
}