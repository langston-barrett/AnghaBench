#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int addr; int eax; int ebx; } ;

/* Variables and functions */
 TYPE_1__ v86 ; 
 int /*<<< orphan*/  v86int () ; 

__attribute__((used)) static inline void
putc(int c)
{

	v86.addr = 0x10;
	v86.eax = 0xe00 | (c & 0xff);
	v86.ebx = 0x7;
	v86int();
}