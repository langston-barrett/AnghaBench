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
typedef  int /*<<< orphan*/  vlc_object_t ;
struct TYPE_2__ {scalar_t__ p_sys; } ;
typedef  TYPE_1__ stream_t ;
typedef  int /*<<< orphan*/  imem_sys_t ;

/* Variables and functions */
 int /*<<< orphan*/  CloseCommon (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void CloseAccess(vlc_object_t *object)
{
    stream_t *access = (stream_t *)object;

    CloseCommon((imem_sys_t*)access->p_sys);
}