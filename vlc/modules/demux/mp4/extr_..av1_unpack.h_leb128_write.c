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
typedef  int uint8_t ;
typedef  int uint32_t ;

/* Variables and functions */

__attribute__((used)) static inline void leb128_write(uint32_t v, uint8_t *p)
{
    for(;;)
    {
        *p = v & 0x7F;
        v >>= 7;
        if(v == 0)
            break;
        *p++ |= 0x80;
    }
}