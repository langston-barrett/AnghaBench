#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {struct pinctrl_map* configs; } ;
struct TYPE_4__ {TYPE_1__ configs; } ;
struct pinctrl_map {int type; TYPE_2__ data; } ;
struct pinctrl_dev {int dummy; } ;

/* Variables and functions */
#define  PIN_MAP_TYPE_CONFIGS_GROUP 129 
#define  PIN_MAP_TYPE_CONFIGS_PIN 128 
 int /*<<< orphan*/  kfree (struct pinctrl_map*) ; 

void pinctrl_utils_free_map(struct pinctrl_dev *pctldev,
	      struct pinctrl_map *map, unsigned num_maps)
{
	int i;

	for (i = 0; i < num_maps; i++) {
		switch (map[i].type) {
		case PIN_MAP_TYPE_CONFIGS_GROUP:
		case PIN_MAP_TYPE_CONFIGS_PIN:
			kfree(map[i].data.configs.configs);
			break;
		default:
			break;
		}
	}
	kfree(map);
}