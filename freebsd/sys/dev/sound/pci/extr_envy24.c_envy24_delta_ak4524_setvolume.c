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
struct envy24_delta_ak4524_codec {int /*<<< orphan*/  info; TYPE_1__* parent; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  device_printf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  spicds_set (int /*<<< orphan*/ ,int,unsigned int,unsigned int) ; 

__attribute__((used)) static void
envy24_delta_ak4524_setvolume(void *codec, int dir, unsigned int left, unsigned int right)
{
	struct envy24_delta_ak4524_codec *ptr = codec;
	if (ptr == NULL)
		return;
#if(0)
	device_printf(ptr->parent->dev, "envy24_delta_ak4524_set()\n");
#endif

	spicds_set(ptr->info, dir, left, right);
}