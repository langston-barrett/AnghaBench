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
struct snd_pcm_hw_params {int dummy; } ;
struct oxygen {struct dg* model_data; } ;
struct dg {unsigned char* cs4245_shadow; } ;

/* Variables and functions */
 size_t CS4245_DAC_CTRL_1 ; 
 unsigned char CS4245_DAC_FM_DOUBLE ; 
 unsigned char CS4245_DAC_FM_MASK ; 
 unsigned char CS4245_DAC_FM_QUAD ; 
 unsigned char CS4245_DAC_FM_SINGLE ; 
 unsigned char CS4245_MCLK1_MASK ; 
 unsigned char CS4245_MCLK1_SHIFT ; 
 unsigned char CS4245_MCLK_1 ; 
 unsigned char CS4245_MCLK_2 ; 
 size_t CS4245_MCLK_FREQ ; 
 int /*<<< orphan*/  cs4245_write_spi (struct oxygen*,size_t) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 

void set_cs4245_dac_params(struct oxygen *chip,
				  struct snd_pcm_hw_params *params)
{
	struct dg *data = chip->model_data;
	unsigned char dac_ctrl;
	unsigned char mclk_freq;

	dac_ctrl = data->cs4245_shadow[CS4245_DAC_CTRL_1] & ~CS4245_DAC_FM_MASK;
	mclk_freq = data->cs4245_shadow[CS4245_MCLK_FREQ] & ~CS4245_MCLK1_MASK;
	if (params_rate(params) <= 50000) {
		dac_ctrl |= CS4245_DAC_FM_SINGLE;
		mclk_freq |= CS4245_MCLK_1 << CS4245_MCLK1_SHIFT;
	} else if (params_rate(params) <= 100000) {
		dac_ctrl |= CS4245_DAC_FM_DOUBLE;
		mclk_freq |= CS4245_MCLK_1 << CS4245_MCLK1_SHIFT;
	} else {
		dac_ctrl |= CS4245_DAC_FM_QUAD;
		mclk_freq |= CS4245_MCLK_2 << CS4245_MCLK1_SHIFT;
	}
	data->cs4245_shadow[CS4245_DAC_CTRL_1] = dac_ctrl;
	data->cs4245_shadow[CS4245_MCLK_FREQ] = mclk_freq;
	cs4245_write_spi(chip, CS4245_DAC_CTRL_1);
	cs4245_write_spi(chip, CS4245_MCLK_FREQ);
}