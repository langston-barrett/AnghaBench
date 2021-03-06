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
struct tegra_dpaux {int /*<<< orphan*/  dev; scalar_t__ regs; } ;

/* Variables and functions */
 int /*<<< orphan*/  readl (scalar_t__) ; 
 int /*<<< orphan*/  trace_dpaux_readl (int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u32 tegra_dpaux_readl(struct tegra_dpaux *dpaux,
				    unsigned int offset)
{
	u32 value = readl(dpaux->regs + (offset << 2));

	trace_dpaux_readl(dpaux->dev, offset, value);

	return value;
}