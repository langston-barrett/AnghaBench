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

/* Variables and functions */
 unsigned int ni_65xx_channels_per_port ; 

__attribute__((used)) static inline unsigned ni_65xx_port_by_channel(unsigned channel)
{
	return channel / ni_65xx_channels_per_port;
}