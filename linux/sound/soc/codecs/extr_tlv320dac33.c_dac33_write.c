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
typedef  unsigned int u8 ;
struct tlv320dac33_priv {int /*<<< orphan*/  i2c; scalar_t__ chip_power; } ;
struct snd_soc_component {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  dac33_write_reg_cache (struct snd_soc_component*,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int) ; 
 int i2c_master_send (int /*<<< orphan*/ ,unsigned int*,int) ; 
 struct tlv320dac33_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 

__attribute__((used)) static int dac33_write(struct snd_soc_component *component, unsigned int reg,
		       unsigned int value)
{
	struct tlv320dac33_priv *dac33 = snd_soc_component_get_drvdata(component);
	u8 data[2];
	int ret = 0;

	/*
	 * data is
	 *   D15..D8 dac33 register offset
	 *   D7...D0 register data
	 */
	data[0] = reg & 0xff;
	data[1] = value & 0xff;

	dac33_write_reg_cache(component, data[0], data[1]);
	if (dac33->chip_power) {
		ret = i2c_master_send(dac33->i2c, data, 2);
		if (ret != 2)
			dev_err(component->dev, "Write failed (%d)\n", ret);
		else
			ret = 0;
	}

	return ret;
}