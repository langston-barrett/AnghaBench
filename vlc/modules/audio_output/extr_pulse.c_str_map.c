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
 char** bsearch (char const*,char const* const**,size_t,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strcmp_void ; 

__attribute__((used)) static const char *str_map(const char *key, const char *const table[][2],
                           size_t n)
{
     const char **r = bsearch(key, table, n, sizeof (*table), strcmp_void);
     return (r != NULL) ? r[1] : NULL;
}