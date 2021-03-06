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
struct nvbios_init {int execute; } ;

/* Variables and functions */

__attribute__((used)) static inline void
init_exec_force(struct nvbios_init *init, bool exec)
{
	if (exec) init->execute |= 0x04;
	else      init->execute &= 0xfb;
}