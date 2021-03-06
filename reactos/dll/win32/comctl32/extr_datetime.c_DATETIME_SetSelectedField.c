#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int select; scalar_t__ nCharsEntered; } ;
typedef  TYPE_1__ DATETIME_INFO ;

/* Variables and functions */
 int /*<<< orphan*/  DATETIME_ApplySelectedField (TYPE_1__*) ; 

__attribute__((used)) static void
DATETIME_SetSelectedField (DATETIME_INFO *infoPtr, int select)
{
    DATETIME_ApplySelectedField(infoPtr);

    infoPtr->select = select;
    infoPtr->nCharsEntered = 0;
}