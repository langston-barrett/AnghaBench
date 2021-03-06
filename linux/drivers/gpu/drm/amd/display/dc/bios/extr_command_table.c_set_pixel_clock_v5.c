#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  void* uint8_t ;
typedef  scalar_t__ uint32_t ;
typedef  int /*<<< orphan*/  uint16_t ;
struct TYPE_8__ {scalar_t__ SET_EXTERNAL_REF_DIV_SRC; scalar_t__ FORCE_PROGRAMMING_OF_PLL; } ;
struct bp_pixel_clock_parameters {int target_pixel_clock_100hz; TYPE_2__ flags; int /*<<< orphan*/  signal_type; int /*<<< orphan*/  encoder_object_id; scalar_t__ pixel_clock_post_divider; int /*<<< orphan*/  fractional_feedback_divider; scalar_t__ feedback_divider; scalar_t__ reference_divider; int /*<<< orphan*/  controller_id; int /*<<< orphan*/  pll_id; } ;
struct bios_parser {TYPE_1__* cmd_helper; } ;
typedef  enum bp_result { ____Placeholder_bp_result } bp_result ;
typedef  int /*<<< orphan*/  clk ;
struct TYPE_9__ {int /*<<< orphan*/  ucMiscInfo; void* usPixelClock; void* ucEncoderMode; int /*<<< orphan*/  ucTransmitterID; void* ucPostDiv; int /*<<< orphan*/  ulFbDivDecFrac; void* usFbDiv; void* ucRefDiv; void* ucPpll; void* ucCRTC; } ;
struct TYPE_10__ {TYPE_3__ sPCLKInput; } ;
struct TYPE_7__ {scalar_t__ (* encoder_mode_bp_to_atom ) (int /*<<< orphan*/ ,int) ;int /*<<< orphan*/  (* encoder_id_to_atom ) (int /*<<< orphan*/ ) ;scalar_t__ (* controller_id_to_atom ) (int /*<<< orphan*/ ,void**) ;scalar_t__ (* clock_source_id_to_atom ) (int /*<<< orphan*/ ,scalar_t__*) ;} ;
typedef  TYPE_4__ SET_PIXEL_CLOCK_PS_ALLOCATION_V5 ;

/* Variables and functions */
 int BP_RESULT_FAILURE ; 
 int BP_RESULT_OK ; 
 scalar_t__ EXEC_BIOS_CMD_TABLE (int /*<<< orphan*/ ,TYPE_4__) ; 
 int /*<<< orphan*/  PIXEL_CLOCK_MISC_FORCE_PROG_PPLL ; 
 int /*<<< orphan*/  PIXEL_CLOCK_MISC_REF_DIV_SRC ; 
 int /*<<< orphan*/  SetPixelClock ; 
 void* cpu_to_le16 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_le32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dal_graphics_object_id_get_encoder_id (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (TYPE_4__*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ stub1 (int /*<<< orphan*/ ,scalar_t__*) ; 
 scalar_t__ stub2 (int /*<<< orphan*/ ,void**) ; 
 int /*<<< orphan*/  stub3 (int /*<<< orphan*/ ) ; 
 scalar_t__ stub4 (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static enum bp_result set_pixel_clock_v5(
	struct bios_parser *bp,
	struct bp_pixel_clock_parameters *bp_params)
{
	enum bp_result result = BP_RESULT_FAILURE;
	SET_PIXEL_CLOCK_PS_ALLOCATION_V5 clk;
	uint8_t controller_id;
	uint32_t pll_id;

	memset(&clk, 0, sizeof(clk));

	if (bp->cmd_helper->clock_source_id_to_atom(bp_params->pll_id, &pll_id)
			&& bp->cmd_helper->controller_id_to_atom(
					bp_params->controller_id, &controller_id)) {
		clk.sPCLKInput.ucCRTC = controller_id;
		clk.sPCLKInput.ucPpll = (uint8_t)pll_id;
		clk.sPCLKInput.ucRefDiv =
				(uint8_t)(bp_params->reference_divider);
		clk.sPCLKInput.usFbDiv =
				cpu_to_le16((uint16_t)(bp_params->feedback_divider));
		clk.sPCLKInput.ulFbDivDecFrac =
				cpu_to_le32(bp_params->fractional_feedback_divider);
		clk.sPCLKInput.ucPostDiv =
				(uint8_t)(bp_params->pixel_clock_post_divider);
		clk.sPCLKInput.ucTransmitterID =
				bp->cmd_helper->encoder_id_to_atom(
						dal_graphics_object_id_get_encoder_id(
								bp_params->encoder_object_id));
		clk.sPCLKInput.ucEncoderMode =
				(uint8_t)bp->cmd_helper->encoder_mode_bp_to_atom(
						bp_params->signal_type, false);

		/* We need to convert from 100Hz units into 10KHz units */
		clk.sPCLKInput.usPixelClock =
				cpu_to_le16((uint16_t)(bp_params->target_pixel_clock_100hz / 100));

		if (bp_params->flags.FORCE_PROGRAMMING_OF_PLL)
			clk.sPCLKInput.ucMiscInfo |=
					PIXEL_CLOCK_MISC_FORCE_PROG_PPLL;

		if (bp_params->flags.SET_EXTERNAL_REF_DIV_SRC)
			clk.sPCLKInput.ucMiscInfo |=
					PIXEL_CLOCK_MISC_REF_DIV_SRC;

		/* clkV5.ucMiscInfo bit[3:2]= HDMI panel bit depth: =0: 24bpp
		 * =1:30bpp, =2:32bpp
		 * driver choose program it itself, i.e. here we program it
		 * to 888 by default.
		 */

		if (EXEC_BIOS_CMD_TABLE(SetPixelClock, clk))
			result = BP_RESULT_OK;
	}

	return result;
}