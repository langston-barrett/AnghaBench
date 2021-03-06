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
struct nvme_cmd_info {int dummy; } ;

/* Variables and functions */
 int DIV_ROUND_UP (int,int) ; 

__attribute__((used)) static unsigned nvme_queue_extra(int depth)
{
	return DIV_ROUND_UP(depth, 8) + (depth * sizeof(struct nvme_cmd_info));
}