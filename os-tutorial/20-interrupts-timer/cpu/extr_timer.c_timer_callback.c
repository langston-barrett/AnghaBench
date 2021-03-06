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
typedef  int /*<<< orphan*/  registers_t ;

/* Variables and functions */
 int /*<<< orphan*/  int_to_ascii (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  kprint (char*) ; 
 int /*<<< orphan*/  tick ; 

__attribute__((used)) static void timer_callback(registers_t regs) {
    tick++;
    kprint("Tick: ");
    
    char tick_ascii[256];
    int_to_ascii(tick, tick_ascii);
    kprint(tick_ascii);
    kprint("\n");
}