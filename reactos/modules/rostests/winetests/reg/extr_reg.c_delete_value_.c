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
typedef  scalar_t__ LONG ;
typedef  int /*<<< orphan*/  HKEY ;

/* Variables and functions */
 scalar_t__ ERROR_SUCCESS ; 
 scalar_t__ RegDeleteValueA (int /*<<< orphan*/  const,char const*) ; 
 int /*<<< orphan*/  lok (int,char*,scalar_t__) ; 

__attribute__((used)) static void delete_value_(unsigned line, const HKEY hkey, const char *name)
{
    LONG err;

    err = RegDeleteValueA(hkey, name);
    lok(err == ERROR_SUCCESS, "RegDeleteValueA failed: %d\n", err);
}