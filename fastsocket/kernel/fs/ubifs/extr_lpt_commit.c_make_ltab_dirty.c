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
struct ubifs_info {int ltab_lnum; int ltab_offs; int lpt_drty_flgs; int /*<<< orphan*/  ltab_sz; } ;

/* Variables and functions */
 int LTAB_DIRTY ; 
 int /*<<< orphan*/  ubifs_add_lpt_dirt (struct ubifs_info*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int make_ltab_dirty(struct ubifs_info *c, int lnum, int offs)
{
	if (lnum != c->ltab_lnum || offs != c->ltab_offs)
		return 0; /* This ltab node is obsolete */
	if (!(c->lpt_drty_flgs & LTAB_DIRTY)) {
		c->lpt_drty_flgs |= LTAB_DIRTY;
		ubifs_add_lpt_dirt(c, c->ltab_lnum, c->ltab_sz);
	}
	return 0;
}