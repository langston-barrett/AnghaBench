#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {struct TYPE_4__* path; } ;
typedef  TYPE_1__ DeviceNode ;

/* Variables and functions */
 int /*<<< orphan*/  free (TYPE_1__*) ; 

void device_node_array_free(DeviceNode *node, size_t n) {
        size_t i;

        for (i = 0; i < n; i++)
                free(node[i].path);

        free(node);
}