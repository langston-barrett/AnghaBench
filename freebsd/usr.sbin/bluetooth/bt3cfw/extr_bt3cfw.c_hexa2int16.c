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

/* Variables and functions */
 int hexa2int8 (char const*) ; 

__attribute__((used)) static int 
hexa2int16(const char *a)
{
	return ((hexa2int8(a) << 8) | hexa2int8(a + 2));
}