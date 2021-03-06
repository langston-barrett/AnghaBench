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
typedef  scalar_t__ u32 ;
struct spider_net_card {scalar_t__ regs; } ;

/* Variables and functions */
 scalar_t__ in_be32 (scalar_t__) ; 

__attribute__((used)) static inline u32
spider_net_read_reg(struct spider_net_card *card, u32 reg)
{
	/* We use the powerpc specific variants instead of readl_be() because
	 * we know spidernet is not a real PCI device and we can thus avoid the
	 * performance hit caused by the PCI workarounds.
	 */
	return in_be32(card->regs + reg);
}