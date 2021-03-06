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
typedef  int uint32_t ;

/* Variables and functions */
 int* crc32_table ; 

__attribute__((used)) static uint32_t crc32(uint32_t crc,
		      const unsigned char *buf,
		      unsigned int len)
{
	crc = crc ^ 0xffffffffUL;
	do {
		crc = crc32_table[((int)crc ^ (*buf++)) & 0xff] ^ (crc >> 8);
	} while (--len);
	return crc ^ 0xffffffffUL;
}