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
typedef  int /*<<< orphan*/  tOptions ;
typedef  int /*<<< orphan*/  tOptDesc ;

/* Variables and functions */
 int NTP_KEYGEN_EXIT_SUCCESS ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  ntp_keygenOptions ; 
 int /*<<< orphan*/  optionUsage (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void
doUsageOpt(tOptions * opts, tOptDesc * od)
{
    int ex_code;
    ex_code = NTP_KEYGEN_EXIT_SUCCESS;
    optionUsage(&ntp_keygenOptions, ex_code);
    /* NOTREACHED */
    exit(1);
    (void)opts;
    (void)od;
}