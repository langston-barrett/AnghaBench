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

__attribute__((used)) static int
neon_bits_same_in_bytes (unsigned imm)
{
  return ((imm & 0x000000ff) == 0 || (imm & 0x000000ff) == 0x000000ff)
         && ((imm & 0x0000ff00) == 0 || (imm & 0x0000ff00) == 0x0000ff00)
         && ((imm & 0x00ff0000) == 0 || (imm & 0x00ff0000) == 0x00ff0000)
         && ((imm & 0xff000000) == 0 || (imm & 0xff000000) == 0xff000000);
}