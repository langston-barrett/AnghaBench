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
typedef  int /*<<< orphan*/  LRESULT ;
typedef  int /*<<< orphan*/  HEADER_INFO ;

/* Variables and functions */
 int /*<<< orphan*/  HEADER_SetItemBounds (int /*<<< orphan*/ *) ; 

__attribute__((used)) static LRESULT
HEADER_Size (HEADER_INFO *infoPtr)
{
    HEADER_SetItemBounds(infoPtr);
    return 0;
}