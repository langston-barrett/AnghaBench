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
struct ath_hal {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  AR_DIAG_SW ; 
 int AR_DIAG_SW_DIS_RX ; 
 int OS_REG_READ (struct ath_hal*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ar5210UpdateDiagReg (struct ath_hal*,int) ; 

void
ar5210StopPcuReceive(struct ath_hal *ah)
{
	ar5210UpdateDiagReg(ah,
		OS_REG_READ(ah, AR_DIAG_SW) | AR_DIAG_SW_DIS_RX);
}