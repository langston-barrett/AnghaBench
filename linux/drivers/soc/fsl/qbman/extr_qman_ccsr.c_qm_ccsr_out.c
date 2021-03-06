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
typedef  int u32 ;

/* Variables and functions */
 int /*<<< orphan*/  iowrite32be (int,scalar_t__) ; 
 scalar_t__ qm_ccsr_start ; 

__attribute__((used)) static inline void qm_ccsr_out(u32 offset, u32 val)
{
	iowrite32be(val, qm_ccsr_start + offset/4);
}