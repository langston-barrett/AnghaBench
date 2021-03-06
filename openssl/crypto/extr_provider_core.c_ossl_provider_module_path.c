#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  module; } ;
typedef  TYPE_1__ OSSL_PROVIDER ;

/* Variables and functions */
 char const* DSO_get_filename (int /*<<< orphan*/ ) ; 

const char *ossl_provider_module_path(const OSSL_PROVIDER *prov)
{
#ifdef FIPS_MODE
    return NULL;
#else
    /* FIXME: Ensure it's a full path */
    return DSO_get_filename(prov->module);
#endif
}