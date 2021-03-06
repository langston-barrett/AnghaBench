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
typedef  int /*<<< orphan*/  obs_data_item_t ;

/* Variables and functions */
 char const* get_item_name (int /*<<< orphan*/ *) ; 

const char *obs_data_item_get_name(obs_data_item_t *item)
{
	if (!item)
		return NULL;

	return get_item_name(item);
}