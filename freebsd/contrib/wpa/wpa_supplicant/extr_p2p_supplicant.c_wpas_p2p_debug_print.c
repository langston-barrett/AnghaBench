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
struct wpa_supplicant {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  wpa_msg_global (struct wpa_supplicant*,int,char*,char const*) ; 

__attribute__((used)) static void wpas_p2p_debug_print(void *ctx, int level, const char *msg)
{
	struct wpa_supplicant *wpa_s = ctx;
	wpa_msg_global(wpa_s, level, "P2P: %s", msg);
}