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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
struct adapter {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  t3_read_reg (struct adapter*,unsigned int) ; 

__attribute__((used)) static __inline void
reg_block_dump(struct adapter *ap, uint8_t *buf, unsigned int start,
    unsigned int end)
{
	uint32_t *p = (uint32_t *)(buf + start);

	for ( ; start <= end; start += sizeof(uint32_t))
		*p++ = t3_read_reg(ap, start);
}