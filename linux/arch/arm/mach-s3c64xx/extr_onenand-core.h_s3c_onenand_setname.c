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
struct TYPE_2__ {char* name; } ;

/* Variables and functions */
 TYPE_1__ s3c_device_onenand ; 

__attribute__((used)) static inline void s3c_onenand_setname(char *name)
{
#ifdef CONFIG_S3C_DEV_ONENAND
	s3c_device_onenand.name = name;
#endif
}