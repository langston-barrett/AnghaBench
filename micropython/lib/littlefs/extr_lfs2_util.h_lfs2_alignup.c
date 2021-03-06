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
typedef  scalar_t__ uint32_t ;

/* Variables and functions */
 scalar_t__ lfs2_aligndown (scalar_t__,scalar_t__) ; 

__attribute__((used)) static inline uint32_t lfs2_alignup(uint32_t a, uint32_t alignment) {
    return lfs2_aligndown(a + alignment-1, alignment);
}