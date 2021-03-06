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
struct rocker_desc_info {TYPE_1__* desc; } ;
struct TYPE_2__ {uintptr_t cookie; } ;

/* Variables and functions */

__attribute__((used)) static void rocker_desc_cookie_ptr_set(const struct rocker_desc_info *desc_info,
				       void *ptr)
{
	desc_info->desc->cookie = (uintptr_t) ptr;
}