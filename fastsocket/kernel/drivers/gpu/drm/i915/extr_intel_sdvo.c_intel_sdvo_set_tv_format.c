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
typedef  int uint32_t ;
struct intel_sdvo_tv_format {int dummy; } ;
struct intel_sdvo {int tv_format_index; } ;
typedef  int /*<<< orphan*/  format_map ;
typedef  int /*<<< orphan*/  format ;

/* Variables and functions */
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int /*<<< orphan*/  SDVO_CMD_SET_TV_FORMAT ; 
 int intel_sdvo_set_value (struct intel_sdvo*,int /*<<< orphan*/ ,struct intel_sdvo_tv_format*,int) ; 
 int /*<<< orphan*/  memcpy (struct intel_sdvo_tv_format*,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct intel_sdvo_tv_format*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  min (int,int) ; 

__attribute__((used)) static bool intel_sdvo_set_tv_format(struct intel_sdvo *intel_sdvo)
{
	struct intel_sdvo_tv_format format;
	uint32_t format_map;

	format_map = 1 << intel_sdvo->tv_format_index;
	memset(&format, 0, sizeof(format));
	memcpy(&format, &format_map, min(sizeof(format), sizeof(format_map)));

	BUILD_BUG_ON(sizeof(format) != 6);
	return intel_sdvo_set_value(intel_sdvo,
				    SDVO_CMD_SET_TV_FORMAT,
				    &format, sizeof(format));
}