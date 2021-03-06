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
typedef  int /*<<< orphan*/  u_int32_t ;
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 int AGP_ENABLE (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int
agp_enable(device_t dev, u_int32_t mode)
{
	return AGP_ENABLE(dev, mode);
}