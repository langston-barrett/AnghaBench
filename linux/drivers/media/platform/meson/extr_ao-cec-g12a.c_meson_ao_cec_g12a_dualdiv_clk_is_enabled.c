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
struct meson_ao_cec_g12a_dualdiv_clk {int /*<<< orphan*/  regmap; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 int CECB_CLK_CNTL_INPUT_EN ; 
 int CECB_CLK_CNTL_OUTPUT_EN ; 
 int /*<<< orphan*/  CECB_CLK_CNTL_REG0 ; 
 struct meson_ao_cec_g12a_dualdiv_clk* hw_to_meson_ao_cec_g12a_dualdiv_clk (struct clk_hw*) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 

__attribute__((used)) static int meson_ao_cec_g12a_dualdiv_clk_is_enabled(struct clk_hw *hw)
{
	struct meson_ao_cec_g12a_dualdiv_clk *dualdiv_clk =
		hw_to_meson_ao_cec_g12a_dualdiv_clk(hw);
	int val;

	regmap_read(dualdiv_clk->regmap, CECB_CLK_CNTL_REG0, &val);

	return !!(val & (CECB_CLK_CNTL_INPUT_EN | CECB_CLK_CNTL_OUTPUT_EN));
}