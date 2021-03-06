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
 int sscanf (char const*,char*,unsigned int*) ; 
 scalar_t__ strcmp (char const*,char*) ; 

__attribute__((used)) static int
parse_integer(unsigned int *u, const char *s)
{
    if(strcmp(s, "-") == 0)
	return 0;
    if (sscanf(s, "%u", u) != 1)
	return -1;
    return 1;
}