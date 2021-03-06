#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zdev_t ;
typedef  void* u8_t ;
struct TYPE_3__ {void* LEDCtrlFlagFromReg; void* LEDCtrlType; } ;
struct TYPE_4__ {TYPE_1__ ledStruct; } ;

/* Variables and functions */
 TYPE_2__* wd ; 
 int /*<<< orphan*/  zmw_declare_for_critical_section () ; 
 int /*<<< orphan*/  zmw_enter_critical_section (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  zmw_get_wlan_dev (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  zmw_leave_critical_section (int /*<<< orphan*/ *) ; 

void zfiWlanSetLEDCtrlParam(zdev_t* dev, u8_t type, u8_t flag)
{
    zmw_get_wlan_dev(dev);

    zmw_declare_for_critical_section();

    zmw_enter_critical_section(dev);
    wd->ledStruct.LEDCtrlType = type;
    wd->ledStruct.LEDCtrlFlagFromReg  = flag;
    zmw_leave_critical_section(dev);
}