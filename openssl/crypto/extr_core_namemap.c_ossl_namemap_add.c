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
typedef  int /*<<< orphan*/  OSSL_NAMEMAP ;

/* Variables and functions */
 int ossl_namemap_add_n (int /*<<< orphan*/ *,int,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlen (char const*) ; 

int ossl_namemap_add(OSSL_NAMEMAP *namemap, int number, const char *name)
{
    if (name == NULL)
        return 0;

    return ossl_namemap_add_n(namemap, number, name, strlen(name));
}