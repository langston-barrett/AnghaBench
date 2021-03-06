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
typedef  int u32 ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;
typedef  enum da7219_aad_adc_1bit_rpt { ____Placeholder_da7219_aad_adc_1bit_rpt } da7219_aad_adc_1bit_rpt ;

/* Variables and functions */
 int DA7219_AAD_ADC_1BIT_RPT_1 ; 
 int DA7219_AAD_ADC_1BIT_RPT_2 ; 
 int DA7219_AAD_ADC_1BIT_RPT_4 ; 
 int DA7219_AAD_ADC_1BIT_RPT_8 ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static enum da7219_aad_adc_1bit_rpt
	da7219_aad_fw_adc_1bit_rpt(struct snd_soc_component *component, u32 val)
{
	switch (val) {
	case 1:
		return DA7219_AAD_ADC_1BIT_RPT_1;
	case 2:
		return DA7219_AAD_ADC_1BIT_RPT_2;
	case 4:
		return DA7219_AAD_ADC_1BIT_RPT_4;
	case 8:
		return DA7219_AAD_ADC_1BIT_RPT_8;
	default:
		dev_warn(component->dev, "Invalid ADC 1-bit repeat value");
		return DA7219_AAD_ADC_1BIT_RPT_1;
	}
}