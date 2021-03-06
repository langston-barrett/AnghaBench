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
typedef  int /*<<< orphan*/  heim_oid ;

/* Variables and functions */
 int der_copy_oid (int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 
 int der_parse_heim_oid (char const*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  errx (int,char*,char const*) ; 

__attribute__((used)) static void
parse_oid(const char *str, const heim_oid *def, heim_oid *oid)
{
    int ret;
    if (str)
	ret = der_parse_heim_oid (str, " .", oid);
    else
	ret = der_copy_oid(def, oid);
    if  (ret)
	errx(1, "parse_oid failed for: %s", str ? str : "default oid");
}