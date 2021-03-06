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
struct ext2fs_extattr_entry {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  M_TEMP ; 
 int /*<<< orphan*/  free (struct ext2fs_extattr_entry*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
free_entry(struct ext2fs_extattr_entry *entry)
{

	free(entry, M_TEMP);
}