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
typedef  union map_info {int dummy; } map_info ;
struct dm_target {int dummy; } ;
struct bio {int dummy; } ;

/* Variables and functions */
 int EIO ; 

__attribute__((used)) static int io_err_map(struct dm_target *tt, struct bio *bio,
		      union map_info *map_context)
{
	return -EIO;
}