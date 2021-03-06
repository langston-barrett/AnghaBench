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
typedef  int /*<<< orphan*/  pte_osSemaphoreHandle ;
typedef  int /*<<< orphan*/  pte_osResult ;

/* Variables and functions */
 int /*<<< orphan*/  PTE_OS_OK ; 
 int /*<<< orphan*/  sceKernelSignalSema (int /*<<< orphan*/ ,int) ; 

pte_osResult pte_osSemaphorePost(pte_osSemaphoreHandle handle, int count)
{
   sceKernelSignalSema(handle, count);

   return PTE_OS_OK;
}