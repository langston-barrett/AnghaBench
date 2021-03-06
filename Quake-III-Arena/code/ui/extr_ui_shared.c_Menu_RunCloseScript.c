#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int flags; } ;
struct TYPE_7__ {scalar_t__ onClose; TYPE_1__ window; } ;
typedef  TYPE_2__ menuDef_t ;
struct TYPE_8__ {TYPE_2__* parent; } ;
typedef  TYPE_3__ itemDef_t ;

/* Variables and functions */
 int /*<<< orphan*/  Item_RunScript (TYPE_3__*,scalar_t__) ; 
 int WINDOW_VISIBLE ; 

__attribute__((used)) static void Menu_RunCloseScript(menuDef_t *menu) {
	if (menu && menu->window.flags & WINDOW_VISIBLE && menu->onClose) {
		itemDef_t item;
    item.parent = menu;
    Item_RunScript(&item, menu->onClose);
	}
}