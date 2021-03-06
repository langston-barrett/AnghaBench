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
struct libinput_device {int dummy; } ;
typedef  enum libinput_config_middle_emulation_state { ____Placeholder_libinput_config_middle_emulation_state } libinput_config_middle_emulation_state ;

/* Variables and functions */
 int /*<<< orphan*/  SWAY_DEBUG ; 
 int libinput_device_config_middle_emulation_get_enabled (struct libinput_device*) ; 
 int /*<<< orphan*/  libinput_device_config_middle_emulation_is_available (struct libinput_device*) ; 
 int /*<<< orphan*/  libinput_device_config_middle_emulation_set_enabled (struct libinput_device*,int) ; 
 int /*<<< orphan*/  log_status (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sway_log (int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static bool set_middle_emulation(struct libinput_device *dev,
		enum libinput_config_middle_emulation_state mid) {
	if (!libinput_device_config_middle_emulation_is_available(dev) ||
			libinput_device_config_middle_emulation_get_enabled(dev) == mid) {
		return false;
	}
	sway_log(SWAY_DEBUG, "middle_emulation_set_enabled(%d)", mid);
	log_status(libinput_device_config_middle_emulation_set_enabled(dev, mid));
	return true;
}