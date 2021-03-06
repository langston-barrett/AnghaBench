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
 scalar_t__ BTA_DisableBluetooth () ; 
 scalar_t__ BTA_SUCCESS ; 
 int /*<<< orphan*/  BTC_MAIN_DISABLE_FUTURE ; 
 int /*<<< orphan*/  FUTURE_FAIL ; 
 int /*<<< orphan*/  btc_config_shut_down () ; 
 int /*<<< orphan*/ * btc_main_get_future_p (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  future_ready (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void btc_disable_bluetooth(void)
{
#if (SMP_INCLUDED)
    btc_config_shut_down();
#endif
    if (BTA_DisableBluetooth() != BTA_SUCCESS) {
        future_ready(*btc_main_get_future_p(BTC_MAIN_DISABLE_FUTURE), FUTURE_FAIL);
    }
}