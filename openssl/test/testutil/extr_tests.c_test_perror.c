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
 int /*<<< orphan*/  TEST_error (char*,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  strerror (int /*<<< orphan*/ ) ; 

void test_perror(const char *s)
{
    /*
     * Using openssl_strerror_r causes linking issues since it isn't
     * exported from libcrypto.so
     */
    TEST_error("%s: %s", s, strerror(errno));
}