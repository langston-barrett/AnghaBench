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
typedef  scalar_t__ u32 ;

/* Variables and functions */
 scalar_t__ grcan_ring_add (scalar_t__,scalar_t__,scalar_t__) ; 

__attribute__((used)) static inline u32 grcan_ring_sub(u32 a, u32 b, u32 size)
{
	return grcan_ring_add(a, size - b, size);
}