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
typedef  int /*<<< orphan*/  vlc_object_t ;

/* Variables and functions */
 int Start_LuaIntf (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

int Open_LuaIntf( vlc_object_t *p_this )
{
    return Start_LuaIntf( p_this, NULL );
}