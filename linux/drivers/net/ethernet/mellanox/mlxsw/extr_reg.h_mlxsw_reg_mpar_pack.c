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
typedef  int /*<<< orphan*/  u8 ;
typedef  enum mlxsw_reg_mpar_i_e { ____Placeholder_mlxsw_reg_mpar_i_e } mlxsw_reg_mpar_i_e ;

/* Variables and functions */
 int /*<<< orphan*/  MLXSW_REG_ZERO (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  mlxsw_reg_mpar_enable_set (char*,int) ; 
 int /*<<< orphan*/  mlxsw_reg_mpar_i_e_set (char*,int) ; 
 int /*<<< orphan*/  mlxsw_reg_mpar_local_port_set (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlxsw_reg_mpar_pa_id_set (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpar ; 

__attribute__((used)) static inline void mlxsw_reg_mpar_pack(char *payload, u8 local_port,
				       enum mlxsw_reg_mpar_i_e i_e,
				       bool enable, u8 pa_id)
{
	MLXSW_REG_ZERO(mpar, payload);
	mlxsw_reg_mpar_local_port_set(payload, local_port);
	mlxsw_reg_mpar_enable_set(payload, enable);
	mlxsw_reg_mpar_i_e_set(payload, i_e);
	mlxsw_reg_mpar_pa_id_set(payload, pa_id);
}