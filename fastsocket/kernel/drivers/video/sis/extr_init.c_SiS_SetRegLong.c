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
typedef  int /*<<< orphan*/  SISIOADDRESS ;

/* Variables and functions */
 int /*<<< orphan*/  OutPortLong (int /*<<< orphan*/ ,unsigned int) ; 

void
SiS_SetRegLong(SISIOADDRESS port, unsigned int data)
{
   OutPortLong(port, data);
}