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
typedef  int /*<<< orphan*/  DH ;

/* Variables and functions */
 int DH_CHECK_P_NOT_PRIME ; 
 int /*<<< orphan*/  DH_F_DH_CHECK_PARAMS_EX ; 
 int DH_NOT_SUITABLE_GENERATOR ; 
 int /*<<< orphan*/  DH_R_CHECK_P_NOT_PRIME ; 
 int /*<<< orphan*/  DH_R_NOT_SUITABLE_GENERATOR ; 
 int /*<<< orphan*/  DH_check_params (int /*<<< orphan*/  const*,int*) ; 
 int /*<<< orphan*/  DHerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int DH_check_params_ex(const DH *dh)
{
    int errflags = 0;

    if (!DH_check_params(dh, &errflags))
        return 0;

    if ((errflags & DH_CHECK_P_NOT_PRIME) != 0)
        DHerr(DH_F_DH_CHECK_PARAMS_EX, DH_R_CHECK_P_NOT_PRIME);
    if ((errflags & DH_NOT_SUITABLE_GENERATOR) != 0)
        DHerr(DH_F_DH_CHECK_PARAMS_EX, DH_R_NOT_SUITABLE_GENERATOR);

    return errflags == 0;
}