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
typedef  int /*<<< orphan*/  gentity_t ;

/* Variables and functions */
 int /*<<< orphan*/  InitShooter (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WP_ROCKET_LAUNCHER ; 

void SP_shooter_rocket( gentity_t *ent ) {
	InitShooter( ent, WP_ROCKET_LAUNCHER );
}