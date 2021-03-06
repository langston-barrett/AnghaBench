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
 int /*<<< orphan*/  OOM () ; 
 scalar_t__ maxmem ; 
 int /*<<< orphan*/  xmlMemFree (void*) ; 
 void* xmlMemMalloc (size_t) ; 
 scalar_t__ xmlMemUsed () ; 

__attribute__((used)) static void *
myMallocFunc(size_t size)
{
    void *ret;

    ret = xmlMemMalloc(size);
    if (ret != NULL) {
        if (xmlMemUsed() > maxmem) {
            OOM();
            xmlMemFree(ret);
            return (NULL);
        }
    }
    return (ret);
}