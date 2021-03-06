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
typedef  int /*<<< orphan*/  atf_error_t ;

/* Variables and functions */
 int /*<<< orphan*/  PRE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  atf_libc_error (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  atf_no_error () ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/ * mkdtemp (char*) ; 
 int /*<<< orphan*/ * strstr (char*,char*) ; 

__attribute__((used)) static
atf_error_t
do_mkdtemp(char *tmpl)
{
    atf_error_t err;

    PRE(strstr(tmpl, "XXXXXX") != NULL);

    if (mkdtemp(tmpl) == NULL)
        err = atf_libc_error(errno, "Cannot create temporary directory "
                             "with template '%s'", tmpl);
    else
        err = atf_no_error();

    return err;
}