#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  widget ;
struct TYPE_2__ {int size; } ;
typedef  TYPE_1__ icon ;

/* Variables and functions */
 scalar_t__ widget_padding_get_padding_height (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int icon_get_desired_height ( widget *widget )
{
    icon *b     = (icon *) widget;
    int  height = b->size;
    height += widget_padding_get_padding_height ( widget );
    return height;
}