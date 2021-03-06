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
struct ata_link {int /*<<< orphan*/  eh_context; } ;

/* Variables and functions */
 int EAGAIN ; 
 unsigned long* sata_ehc_deb_timing (int /*<<< orphan*/ *) ; 
 int sata_link_hardreset (struct ata_link*,unsigned long const*,unsigned long,int*,int /*<<< orphan*/ *) ; 

int sata_std_hardreset(struct ata_link *link, unsigned int *class,
		       unsigned long deadline)
{
	const unsigned long *timing = sata_ehc_deb_timing(&link->eh_context);
	bool online;
	int rc;

	/* do hardreset */
	rc = sata_link_hardreset(link, timing, deadline, &online, NULL);
	return online ? -EAGAIN : rc;
}