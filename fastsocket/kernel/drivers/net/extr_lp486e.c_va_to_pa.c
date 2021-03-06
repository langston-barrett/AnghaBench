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
typedef  int /*<<< orphan*/  phys_addr ;

/* Variables and functions */
 int /*<<< orphan*/  I596_NULL ; 
 int /*<<< orphan*/  virt_to_bus (void*) ; 

__attribute__((used)) static inline phys_addr
va_to_pa(void *x) {
	return x ? virt_to_bus(x) : I596_NULL;
}