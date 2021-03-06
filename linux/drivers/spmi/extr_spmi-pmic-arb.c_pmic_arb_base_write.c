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
struct spmi_pmic_arb {scalar_t__ wr_base; } ;

/* Variables and functions */
 int /*<<< orphan*/  writel_relaxed (scalar_t__,scalar_t__) ; 

__attribute__((used)) static inline void pmic_arb_base_write(struct spmi_pmic_arb *pmic_arb,
				       u32 offset, u32 val)
{
	writel_relaxed(val, pmic_arb->wr_base + offset);
}