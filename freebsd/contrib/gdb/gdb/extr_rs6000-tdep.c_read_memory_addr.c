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
typedef  int /*<<< orphan*/  CORE_ADDR ;

/* Variables and functions */
 int /*<<< orphan*/  read_memory_unsigned_integer (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static CORE_ADDR
read_memory_addr (CORE_ADDR memaddr, int len)
{
  return read_memory_unsigned_integer (memaddr, len);
}