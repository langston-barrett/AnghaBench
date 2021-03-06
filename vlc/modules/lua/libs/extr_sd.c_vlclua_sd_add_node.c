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
typedef  int /*<<< orphan*/  services_discovery_t ;
typedef  int /*<<< orphan*/  lua_State ;

/* Variables and functions */
 scalar_t__ vlclua_get_this (int /*<<< orphan*/ *) ; 
 int vlclua_sd_add_common (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vlclua_sd_create_node (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int vlclua_sd_add_node( lua_State *L )
{
    services_discovery_t *p_sd = (services_discovery_t *)vlclua_get_this( L );

    return vlclua_sd_add_common( p_sd, vlclua_sd_create_node( p_sd, L ) );
}