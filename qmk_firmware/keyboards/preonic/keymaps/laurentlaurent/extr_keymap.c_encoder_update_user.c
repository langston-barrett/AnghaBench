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
typedef  int /*<<< orphan*/  uint8_t ;

/* Variables and functions */
 scalar_t__ IS_LAYER_ON (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  KC_PGDN ; 
 int /*<<< orphan*/  KC_PGUP ; 
 int /*<<< orphan*/  _RAISE ; 
 scalar_t__ muse_mode ; 
 int /*<<< orphan*/  muse_offset ; 
 int muse_tempo ; 
 int /*<<< orphan*/  tap_code (int /*<<< orphan*/ ) ; 

void encoder_update_user(uint8_t index, bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo += 1;
            } else {
                muse_tempo -= 1;
            }
        }
    } else {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
             tap_code(KC_PGUP);
        }
    }
}