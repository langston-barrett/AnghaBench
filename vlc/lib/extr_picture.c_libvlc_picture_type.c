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
typedef  int /*<<< orphan*/  libvlc_picture_type_t ;
struct TYPE_3__ {int /*<<< orphan*/  type; } ;
typedef  TYPE_1__ libvlc_picture_t ;

/* Variables and functions */

libvlc_picture_type_t libvlc_picture_type( const libvlc_picture_t* pic )
{
    return pic->type;
}