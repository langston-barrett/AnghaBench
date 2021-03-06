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
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */
 scalar_t__ PXSEG (unsigned long) ; 
 int /*<<< orphan*/  ctrl_inl (unsigned long) ; 
 int /*<<< orphan*/  ctrl_inw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  maybebadio (unsigned long) ; 
 int /*<<< orphan*/  port2adr (unsigned long) ; 

u32 titan_inl(unsigned long port)
{
        if (PXSEG(port))
                return ctrl_inl(port);
        else if (port >= 0x2000)
                return ctrl_inw(port2adr(port));
        else
                maybebadio(port);
        return 0;
}