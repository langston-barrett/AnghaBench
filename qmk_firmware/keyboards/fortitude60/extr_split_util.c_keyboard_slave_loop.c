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

/* Variables and functions */
 int /*<<< orphan*/  matrix_init () ; 
 int /*<<< orphan*/  matrix_slave_scan () ; 

void keyboard_slave_loop(void) {
   matrix_init();

   while (1) {
      matrix_slave_scan();
   }
}