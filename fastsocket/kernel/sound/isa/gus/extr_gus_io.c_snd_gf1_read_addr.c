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
struct snd_gus_card {int dummy; } ;

/* Variables and functions */
 unsigned int __snd_gf1_read_addr (struct snd_gus_card*,unsigned char,short) ; 

unsigned int snd_gf1_read_addr(struct snd_gus_card * gus,
                               unsigned char reg,
                               short w_16bit)
{
	return __snd_gf1_read_addr(gus, reg, w_16bit);
}