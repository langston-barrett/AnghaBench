#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct snd_soc_dai {TYPE_1__* ops; } ;
struct TYPE_2__ {int (* set_sysclk ) (struct snd_soc_dai*,int,unsigned int,int) ;} ;

/* Variables and functions */
 int EINVAL ; 
 int stub1 (struct snd_soc_dai*,int,unsigned int,int) ; 

int snd_soc_dai_set_sysclk(struct snd_soc_dai *dai, int clk_id,
	unsigned int freq, int dir)
{
	if (dai->ops && dai->ops->set_sysclk)
		return dai->ops->set_sysclk(dai, clk_id, freq, dir);
	else
		return -EINVAL;
}