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
struct TYPE_2__ {int /*<<< orphan*/  time; int /*<<< orphan*/  voiceTime; } ;

/* Variables and functions */
 int /*<<< orphan*/  Menus_OpenByName (char*) ; 
 TYPE_1__ cg ; 
 int /*<<< orphan*/  trap_Cvar_Set (char*,char*) ; 

void CG_ShowResponseHead() {
  Menus_OpenByName("voiceMenu");
	trap_Cvar_Set("cl_conXOffset", "72");
	cg.voiceTime = cg.time;
}