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
typedef  int uint32_t ;

/* Variables and functions */
 int LocalTime ; 
 int TICKS_PER_MS ; 
 int timingdelay ; 

void Delay(uint32_t nCount)
{
  /* Capture the current local time */
  timingdelay = LocalTime;

  /* wait until the desired delay is finished */
  while( (LocalTime - timingdelay) < (nCount*TICKS_PER_MS) ) {
  }
}