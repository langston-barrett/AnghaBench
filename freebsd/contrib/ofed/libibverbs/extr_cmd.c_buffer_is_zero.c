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
typedef  scalar_t__ ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  memcmp (char*,char*,scalar_t__) ; 

__attribute__((used)) static int buffer_is_zero(char *addr, ssize_t size)
{
	return addr[0] == 0 && !memcmp(addr, addr + 1, size - 1);
}