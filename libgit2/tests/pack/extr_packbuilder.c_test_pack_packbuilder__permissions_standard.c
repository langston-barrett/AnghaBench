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
 int /*<<< orphan*/  GIT_PACK_FILE_MODE ; 
 int /*<<< orphan*/  test_write_pack_permission (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void test_pack_packbuilder__permissions_standard(void)
{
	test_write_pack_permission(0, GIT_PACK_FILE_MODE);
}