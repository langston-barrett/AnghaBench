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
struct snd_soc_component {int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  MT6351_ZCD_CON2 ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static void set_hp_gain_zero(struct snd_soc_component *cmpnt)
{
	regmap_update_bits(cmpnt->regmap, MT6351_ZCD_CON2,
			   0x1f << 7, 0x8 << 7);
	regmap_update_bits(cmpnt->regmap, MT6351_ZCD_CON2,
			   0x1f << 0, 0x8 << 0);
}