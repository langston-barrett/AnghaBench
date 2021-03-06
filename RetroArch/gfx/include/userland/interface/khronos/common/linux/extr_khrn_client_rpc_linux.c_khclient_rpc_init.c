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
 scalar_t__ KHR_SUCCESS ; 
 int /*<<< orphan*/  mutex ; 
 scalar_t__ platform_mutex_create (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * workspace ; 

bool khclient_rpc_init(void)
{
   workspace = NULL;
   return platform_mutex_create(&mutex) == KHR_SUCCESS;
}