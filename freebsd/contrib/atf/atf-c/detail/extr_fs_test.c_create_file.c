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
 int O_CREAT ; 
 int O_TRUNC ; 
 int O_WRONLY ; 
 int /*<<< orphan*/  atf_tc_fail (char*,char const*) ; 
 int /*<<< orphan*/  close (int) ; 
 int open (char const*,int,int) ; 

__attribute__((used)) static
void
create_file(const char *p, int mode)
{
    int fd;

    fd = open(p, O_CREAT | O_WRONLY | O_TRUNC, mode);
    if (fd == -1)
        atf_tc_fail("Could not create helper file %s", p);
    close(fd);
}