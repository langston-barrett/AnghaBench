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
typedef  int /*<<< orphan*/  _u16 ;

/* Variables and functions */
 int /*<<< orphan*/  sl_Memset (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void _SlDrvMemZero(void* Addr, _u16 size)
{
    sl_Memset(Addr, 0, size);
}