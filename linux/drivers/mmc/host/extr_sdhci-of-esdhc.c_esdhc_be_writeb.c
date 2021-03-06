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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct sdhci_host {scalar_t__ ioaddr; } ;

/* Variables and functions */
 int /*<<< orphan*/  esdhc_writeb_fixup (struct sdhci_host*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ioread32be (scalar_t__) ; 
 int /*<<< orphan*/  iowrite32be (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void esdhc_be_writeb(struct sdhci_host *host, u8 val, int reg)
{
	int base = reg & ~0x3;
	u32 value;
	u32 ret;

	value = ioread32be(host->ioaddr + base);
	ret = esdhc_writeb_fixup(host, reg, val, value);
	iowrite32be(ret, host->ioaddr + base);
}