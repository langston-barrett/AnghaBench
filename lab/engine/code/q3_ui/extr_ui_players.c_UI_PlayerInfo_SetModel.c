#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {void* weapon; int /*<<< orphan*/  newModel; int /*<<< orphan*/  chat; scalar_t__ weaponTimer; int /*<<< orphan*/  pendingWeapon; void* lastWeapon; void* currentWeapon; } ;
typedef  TYPE_1__ playerInfo_t ;

/* Variables and functions */
 int /*<<< orphan*/  UI_PlayerInfo_SetWeapon (TYPE_1__*,void*) ; 
 int /*<<< orphan*/  UI_RegisterClientModelname (TYPE_1__*,char const*) ; 
 void* WP_NONE ; 
 int /*<<< orphan*/  WP_NUM_WEAPONS ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  qfalse ; 
 int /*<<< orphan*/  qtrue ; 

void UI_PlayerInfo_SetModel( playerInfo_t *pi, const char *model ) {
	memset( pi, 0, sizeof(*pi) );
	UI_RegisterClientModelname( pi, model );
	pi->weapon = WP_NONE;
	pi->currentWeapon = WP_NONE;
	pi->lastWeapon = pi->weapon;
	pi->pendingWeapon = WP_NUM_WEAPONS;
	pi->weaponTimer = 0;
	pi->chat = qfalse;
	pi->newModel = qtrue;
	UI_PlayerInfo_SetWeapon( pi, pi->weapon );
}