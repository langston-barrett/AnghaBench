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
struct snd_ice1712 {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  AK4113_ADDR ; 
 unsigned char snd_vt1724_read_i2c (struct snd_ice1712*,int /*<<< orphan*/ ,unsigned char) ; 

__attribute__((used)) static unsigned char qtet_ak4113_read(void *private_data, unsigned char reg)
{
	return snd_vt1724_read_i2c((struct snd_ice1712 *)private_data,
			AK4113_ADDR, reg);
}