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
typedef  scalar_t__ uint8_t ;
typedef  int uint16_t ;

/* Variables and functions */

__attribute__((used)) static inline uint16_t
unaligned_read16le(const uint8_t *buf)
{
	uint16_t num = ((uint16_t)buf[0]) | ((uint16_t)buf[1] << 8);
	return num;
}