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
 int /*<<< orphan*/  GetDatabaseEncoding () ; 
 scalar_t__ pg_verify_mbstr_len (int /*<<< orphan*/ ,char const*,int,int) ; 

bool
pg_verifymbstr(const char *mbstr, int len, bool noError)
{
	return
		pg_verify_mbstr_len(GetDatabaseEncoding(), mbstr, len, noError) >= 0;
}