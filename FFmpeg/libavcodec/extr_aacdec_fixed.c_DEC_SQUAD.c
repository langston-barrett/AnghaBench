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

/* Variables and functions */

__attribute__((used)) static inline int *DEC_SQUAD(int *dst, unsigned idx)
{
    dst[0] = (idx & 3) - 1;
    dst[1] = (idx >> 2 & 3) - 1;
    dst[2] = (idx >> 4 & 3) - 1;
    dst[3] = (idx >> 6 & 3) - 1;

    return dst + 4;
}