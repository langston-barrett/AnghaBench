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
struct IDAT_list {int /*<<< orphan*/  length; int /*<<< orphan*/ * next; } ;

/* Variables and functions */
 int /*<<< orphan*/  CLEAR (struct IDAT_list) ; 
 int /*<<< orphan*/  IDAT_INIT_LENGTH ; 

__attribute__((used)) static void
IDAT_list_init(struct IDAT_list *list)
{
   CLEAR(*list);

   list->next = NULL;
   list->length = IDAT_INIT_LENGTH;
}