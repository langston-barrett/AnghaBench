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
 int /*<<< orphan*/  ERR_add_error_data (int,char const*,char*,char const*) ; 
 int /*<<< orphan*/  TS_F_TS_CONF_INVALID ; 
 int /*<<< orphan*/  TS_R_VAR_BAD_VALUE ; 
 int /*<<< orphan*/  TSerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ts_CONF_invalid(const char *name, const char *tag)
{
    TSerr(TS_F_TS_CONF_INVALID, TS_R_VAR_BAD_VALUE);
    ERR_add_error_data(3, name, "::", tag);
}