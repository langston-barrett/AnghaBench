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
typedef  int /*<<< orphan*/  zdev_t ;
typedef  int u16_t ;

/* Variables and functions */
 int /*<<< orphan*/  ZM_MAC_REG_BASIC_RATE ; 
 int /*<<< orphan*/  zfDelayWriteInternalReg (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  zfFlushDelayWrite (int /*<<< orphan*/ *) ; 

void zfHpSetBasicRateSet(zdev_t* dev, u16_t bRateBasic, u16_t gRateBasic)
{
    zfDelayWriteInternalReg(dev, ZM_MAC_REG_BASIC_RATE, bRateBasic
                            | ((u16_t)gRateBasic<<8));
    zfFlushDelayWrite(dev);
}