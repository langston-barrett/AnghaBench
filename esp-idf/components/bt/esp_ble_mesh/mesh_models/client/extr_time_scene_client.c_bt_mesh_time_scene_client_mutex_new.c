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
 int /*<<< orphan*/  osi_mutex_new (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  time_scene_client_mutex ; 

__attribute__((used)) static void bt_mesh_time_scene_client_mutex_new(void)
{
    static bool init;

    if (!init) {
        osi_mutex_new(&time_scene_client_mutex);
        init = true;
    }
}