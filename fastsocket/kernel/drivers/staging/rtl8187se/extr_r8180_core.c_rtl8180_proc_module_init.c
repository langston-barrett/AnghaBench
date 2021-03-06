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
struct TYPE_2__ {int /*<<< orphan*/  proc_net; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMESG (char*) ; 
 int /*<<< orphan*/  RTL8180_MODULE_NAME ; 
 int /*<<< orphan*/  S_IFDIR ; 
 int /*<<< orphan*/  create_proc_entry (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_1__ init_net ; 
 int /*<<< orphan*/  rtl8180_proc ; 

void rtl8180_proc_module_init(void)
{
	DMESG("Initializing proc filesystem");
        rtl8180_proc=create_proc_entry(RTL8180_MODULE_NAME, S_IFDIR, init_net.proc_net);
}