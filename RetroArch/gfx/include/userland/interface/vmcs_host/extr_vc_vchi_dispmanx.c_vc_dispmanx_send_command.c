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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  int32_t ;

/* Variables and functions */
 int /*<<< orphan*/  dispmanx_send_command (int /*<<< orphan*/ ,void*,int /*<<< orphan*/ ) ; 

int32_t vc_dispmanx_send_command (uint32_t command, void *buffer,
                                  uint32_t length)
{
  return dispmanx_send_command (command, buffer, length);
}