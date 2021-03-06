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
typedef  int u32 ;

/* Variables and functions */
#define  EINVAL 128 

__attribute__((used)) static inline int numrank(u32 rank)
{
	static int ranks[4] = { 1, 2, 4, -EINVAL };

	return ranks[rank & 0x3];
}