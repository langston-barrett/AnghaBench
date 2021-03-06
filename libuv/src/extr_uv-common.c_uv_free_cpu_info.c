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
struct TYPE_4__ {struct TYPE_4__* model; } ;
typedef  TYPE_1__ uv_cpu_info_t ;

/* Variables and functions */
 int /*<<< orphan*/  uv__free (TYPE_1__*) ; 

void uv_free_cpu_info(uv_cpu_info_t* cpu_infos, int count) {
  int i;

  for (i = 0; i < count; i++)
    uv__free(cpu_infos[i].model);

  uv__free(cpu_infos);
}