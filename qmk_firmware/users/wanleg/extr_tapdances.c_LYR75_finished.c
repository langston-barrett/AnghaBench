#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  qk_tap_dance_state_t ;
struct TYPE_2__ {int state; } ;

/* Variables and functions */
#define  DOUBLE_SINGLE_TAP 130 
#define  DOUBLE_TAP 129 
 int /*<<< orphan*/  KC_PSLS ; 
 TYPE_1__ LYR75tap_state ; 
#define  SINGLE_TAP 128 
 int /*<<< orphan*/  _GK ; 
 int cur_dance (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  register_code (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_single_persistent_default_layer (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  unregister_code (int /*<<< orphan*/ ) ; 

void LYR75_finished (qk_tap_dance_state_t *state, void *user_data) {
  LYR75tap_state.state = cur_dance(state);
  switch (LYR75tap_state.state) {
	case SINGLE_TAP: register_code(KC_PSLS); break;
	case DOUBLE_TAP: set_single_persistent_default_layer(_GK); break;
    case DOUBLE_SINGLE_TAP: register_code(KC_PSLS); unregister_code(KC_PSLS); register_code(KC_PSLS);
  }
}