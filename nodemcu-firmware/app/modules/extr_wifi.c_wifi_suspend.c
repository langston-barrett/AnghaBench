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
typedef  int /*<<< orphan*/  lua_State ;

/* Variables and functions */
 int /*<<< orphan*/  dbg_printf (char*,int /*<<< orphan*/ ) ; 
 int luaL_error (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  susp_note_str ; 
 int /*<<< orphan*/  susp_unavailable_str ; 

__attribute__((used)) static int wifi_suspend(lua_State* L){
  dbg_printf("%s", susp_note_str);
  return luaL_error(L, susp_unavailable_str);
}