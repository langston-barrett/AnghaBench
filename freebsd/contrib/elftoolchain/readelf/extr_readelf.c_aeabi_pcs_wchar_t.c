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
typedef  int /*<<< orphan*/  uintmax_t ;
typedef  int uint64_t ;
typedef  int /*<<< orphan*/  s_wt ;

/* Variables and functions */
 int /*<<< orphan*/  snprintf (char*,int,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static const char *
aeabi_pcs_wchar_t(uint64_t wt)
{
	static char s_wt[32];

	switch (wt) {
	case 0: return "None";
	case 2: return "wchar_t size 2";
	case 4: return "wchar_t size 4";
	default:
		snprintf(s_wt, sizeof(s_wt), "Unknown (%ju)", (uintmax_t) wt);
		return (s_wt);
	}
}