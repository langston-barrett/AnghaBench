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
struct mlxsw_core {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MLXSW_PORT_CPU_PORT ; 
 int /*<<< orphan*/  __mlxsw_core_port_fini (struct mlxsw_core*,int /*<<< orphan*/ ) ; 

void mlxsw_core_cpu_port_fini(struct mlxsw_core *mlxsw_core)
{
	__mlxsw_core_port_fini(mlxsw_core, MLXSW_PORT_CPU_PORT);
}