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
 int tolower (char const) ; 

int strcasecmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && tolower(*s1) == tolower(*s2)) {
        s1++;
        s2++;
    }

    return tolower(*(unsigned char *)s1) - tolower(*(unsigned char *)s2);
}