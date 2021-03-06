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
struct obs_data_item {int /*<<< orphan*/  default_size; } ;
typedef  int /*<<< orphan*/  obs_data_t ;

/* Variables and functions */
 scalar_t__ get_default_data_ptr (struct obs_data_item*) ; 

__attribute__((used)) static inline obs_data_t *get_item_default_obj(struct obs_data_item *item)
{
	if (!item || !item->default_size)
		return NULL;

	return *(obs_data_t **)get_default_data_ptr(item);
}