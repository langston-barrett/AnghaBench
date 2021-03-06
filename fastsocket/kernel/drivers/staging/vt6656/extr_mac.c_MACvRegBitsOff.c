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
typedef  int /*<<< orphan*/  PSDevice ;
typedef  scalar_t__ BYTE ;

/* Variables and functions */
 int /*<<< orphan*/  CONTROLnsRequestOut (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int,scalar_t__*) ; 
 int /*<<< orphan*/  MESSAGE_REQUEST_MACREG ; 
 int /*<<< orphan*/  MESSAGE_TYPE_WRITE_MASK ; 

void MACvRegBitsOff(PSDevice pDevice, BYTE byRegOfs, BYTE byBits)
{
BYTE            pbyData[2];

    pbyData[0] = 0;
    pbyData[1] = byBits;

    CONTROLnsRequestOut(pDevice,
                        MESSAGE_TYPE_WRITE_MASK,
                        byRegOfs,
                        MESSAGE_REQUEST_MACREG,
                        2,
                        pbyData
                        );
}