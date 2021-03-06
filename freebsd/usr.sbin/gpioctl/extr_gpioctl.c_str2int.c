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
 int strlen (char const*) ; 
 int strtod (char const*,char**) ; 

__attribute__((used)) static int
str2int(const char *s, int *ok)
{
	char *endptr;
	int res = strtod(s, &endptr);
	if (endptr != s + strlen(s) )
		*ok = 0;
	else
		*ok = 1;

	return res;
}