#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct snd_kcontrol {int private_value; } ;
struct TYPE_3__ {int max; scalar_t__ min; } ;
struct TYPE_4__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_info {int count; TYPE_2__ value; int /*<<< orphan*/  type; } ;
struct snd_ac97 {int flags; } ;

/* Variables and functions */
 int AC97_STEREO_MUTES ; 
 int /*<<< orphan*/  SNDRV_CTL_ELEM_TYPE_BOOLEAN ; 
 int /*<<< orphan*/  SNDRV_CTL_ELEM_TYPE_INTEGER ; 
 struct snd_ac97* snd_kcontrol_chip (struct snd_kcontrol*) ; 

__attribute__((used)) static int snd_ac97_ad18xx_pcm_info_bits(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
	struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
	int mask = (kcontrol->private_value >> 16) & 0x0f;
	int lshift = (kcontrol->private_value >> 8) & 0x0f;
	int rshift = (kcontrol->private_value >> 12) & 0x0f;

	uinfo->type = mask == 1 ? SNDRV_CTL_ELEM_TYPE_BOOLEAN : SNDRV_CTL_ELEM_TYPE_INTEGER;
	if (lshift != rshift && (ac97->flags & AC97_STEREO_MUTES))
		uinfo->count = 2;
	else
		uinfo->count = 1;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = mask;
	return 0;
}