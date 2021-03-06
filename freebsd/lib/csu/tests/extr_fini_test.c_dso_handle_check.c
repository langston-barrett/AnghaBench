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
 int /*<<< orphan*/  ATF_REQUIRE_MSG (int /*<<< orphan*/ ,char*) ; 
 void* __dso_handle ; 

void
dso_handle_check(void)
{
	void *dso = __dso_handle;

#ifdef DSO_LIB
	ATF_REQUIRE_MSG(dso != NULL,
	    "Null __dso_handle in DSO");
#else
	ATF_REQUIRE_MSG(dso == NULL,
	    "Invalid __dso_handle in non-DSO");
#endif
}