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
typedef  int /*<<< orphan*/  u32 ;
struct mmc_ios {scalar_t__ power_mode; scalar_t__ clock; int bus_width; } ;
struct mmc_host {int dummy; } ;
struct au1xmmc_host {scalar_t__ clock; } ;

/* Variables and functions */
 int /*<<< orphan*/  HOST_CONFIG2 (struct au1xmmc_host*) ; 
#define  MMC_BUS_WIDTH_1 129 
#define  MMC_BUS_WIDTH_4 128 
 scalar_t__ MMC_POWER_OFF ; 
 scalar_t__ MMC_POWER_ON ; 
 int /*<<< orphan*/  SD_CONFIG2_WB ; 
 int /*<<< orphan*/  au1xmmc_set_clock (struct au1xmmc_host*,scalar_t__) ; 
 int /*<<< orphan*/  au1xmmc_set_power (struct au1xmmc_host*,int) ; 
 int /*<<< orphan*/  au_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  au_sync () ; 
 int /*<<< orphan*/  au_writel (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct au1xmmc_host* mmc_priv (struct mmc_host*) ; 

__attribute__((used)) static void au1xmmc_set_ios(struct mmc_host *mmc, struct mmc_ios *ios)
{
	struct au1xmmc_host *host = mmc_priv(mmc);
	u32 config2;

	if (ios->power_mode == MMC_POWER_OFF)
		au1xmmc_set_power(host, 0);
	else if (ios->power_mode == MMC_POWER_ON) {
		au1xmmc_set_power(host, 1);
	}

	if (ios->clock && ios->clock != host->clock) {
		au1xmmc_set_clock(host, ios->clock);
		host->clock = ios->clock;
	}

	config2 = au_readl(HOST_CONFIG2(host));
	switch (ios->bus_width) {
	case MMC_BUS_WIDTH_4:
		config2 |= SD_CONFIG2_WB;
		break;
	case MMC_BUS_WIDTH_1:
		config2 &= ~SD_CONFIG2_WB;
		break;
	}
	au_writel(config2, HOST_CONFIG2(host));
	au_sync();
}