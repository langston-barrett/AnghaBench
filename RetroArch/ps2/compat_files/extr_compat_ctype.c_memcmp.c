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

int memcmp(const void *s1, const void *s2, unsigned int length)
{
    const char *a = s1;
    const char *b = s2;

    while (length--) {
        if (*a++ != *b++)
            return 1;
    }

    return 0;
}