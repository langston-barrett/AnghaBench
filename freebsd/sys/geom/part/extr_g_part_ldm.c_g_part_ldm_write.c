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
struct g_part_table {int dummy; } ;
struct g_consumer {int dummy; } ;

/* Variables and functions */
 int ENOSYS ; 

__attribute__((used)) static int
g_part_ldm_write(struct g_part_table *basetable, struct g_consumer *cp)
{

	return (ENOSYS);
}