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
typedef  int /*<<< orphan*/  js_State ;

/* Variables and functions */
 int /*<<< orphan*/  js_newobject (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  js_pushnumber (int /*<<< orphan*/ *,double const) ; 
 int /*<<< orphan*/  js_setproperty (int /*<<< orphan*/ *,int,char const* const) ; 

__attribute__((used)) static void push_nums_obj(js_State *J, const char * const names[],
                          const double vals[])
{
    js_newobject(J);
    for (int i = 0; names[i]; i++) {
        js_pushnumber(J, vals[i]);
        js_setproperty(J, -2, names[i]);
    }
}