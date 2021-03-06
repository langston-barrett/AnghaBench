#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/ * insertMarkItem; int /*<<< orphan*/ * dropItem; int /*<<< orphan*/ * firstVisible; int /*<<< orphan*/ * focusedItem; int /*<<< orphan*/ * hotItem; int /*<<< orphan*/ * selectedItem; int /*<<< orphan*/  items; } ;
typedef  int /*<<< orphan*/  TREEVIEW_ITEM ;
typedef  TYPE_1__ TREEVIEW_INFO ;

/* Variables and functions */
 int /*<<< orphan*/  DPA_DeletePtr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DPA_GetPtrIndex (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  heap_free (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
TREEVIEW_FreeItem(TREEVIEW_INFO *infoPtr, TREEVIEW_ITEM *item)
{
    DPA_DeletePtr(infoPtr->items, DPA_GetPtrIndex(infoPtr->items, item));
    if (infoPtr->selectedItem == item)
        infoPtr->selectedItem = NULL;
    if (infoPtr->hotItem == item)
        infoPtr->hotItem = NULL;
    if (infoPtr->focusedItem == item)
        infoPtr->focusedItem = NULL;
    if (infoPtr->firstVisible == item)
        infoPtr->firstVisible = NULL;
    if (infoPtr->dropItem == item)
        infoPtr->dropItem = NULL;
    if (infoPtr->insertMarkItem == item)
        infoPtr->insertMarkItem = NULL;
    heap_free(item);
}