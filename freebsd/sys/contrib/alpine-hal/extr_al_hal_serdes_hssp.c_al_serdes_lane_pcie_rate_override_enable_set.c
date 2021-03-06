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
struct al_serdes_grp_obj {int dummy; } ;
typedef  enum al_serdes_reg_page { ____Placeholder_al_serdes_reg_page } al_serdes_reg_page ;
typedef  enum al_serdes_lane { ____Placeholder_al_serdes_lane } al_serdes_lane ;
typedef  scalar_t__ al_bool ;

/* Variables and functions */
 int /*<<< orphan*/  AL_SRDS_REG_TYPE_PCS ; 
 int /*<<< orphan*/  SERDES_IREG_FLD_PCS_VPCSIF_OVR_RATE_ENA ; 
 int /*<<< orphan*/  SERDES_IREG_FLD_PCS_VPCSIF_OVR_RATE_ENA_REG_NUM ; 
 int /*<<< orphan*/  al_serdes_grp_reg_masked_write (struct al_serdes_grp_obj*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void al_serdes_lane_pcie_rate_override_enable_set(
	struct al_serdes_grp_obj	*obj,
	enum al_serdes_lane		lane,
	al_bool				en)
{
	al_serdes_grp_reg_masked_write(
		obj,
		(enum al_serdes_reg_page)lane,
		AL_SRDS_REG_TYPE_PCS,
		SERDES_IREG_FLD_PCS_VPCSIF_OVR_RATE_ENA_REG_NUM,
		SERDES_IREG_FLD_PCS_VPCSIF_OVR_RATE_ENA,
		en ? SERDES_IREG_FLD_PCS_VPCSIF_OVR_RATE_ENA : 0);
}