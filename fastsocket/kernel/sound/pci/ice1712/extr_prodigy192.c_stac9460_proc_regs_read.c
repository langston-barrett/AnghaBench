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
struct snd_info_entry {scalar_t__ private_data; } ;
struct snd_info_buffer {int dummy; } ;
struct snd_ice1712 {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  snd_iprintf (struct snd_info_buffer*,char*,int,int) ; 
 int stac9460_get (struct snd_ice1712*,int) ; 

__attribute__((used)) static void stac9460_proc_regs_read(struct snd_info_entry *entry,
		struct snd_info_buffer *buffer)
{
	struct snd_ice1712 *ice = (struct snd_ice1712 *)entry->private_data;
	int reg, val;
	/* registers 0x0 - 0x14 */
	for (reg = 0; reg <= 0x15; reg++) {
		val = stac9460_get(ice, reg);
		snd_iprintf(buffer, "0x%02x = 0x%02x\n", reg, val);
	}
}