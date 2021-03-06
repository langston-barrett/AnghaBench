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
struct TYPE_3__ {scalar_t__ handle; } ;
struct TYPE_4__ {TYPE_1__ vk; } ;

/* Variables and functions */
 TYPE_2__ _glfw ; 
 int /*<<< orphan*/  _glfw_dlclose (scalar_t__) ; 

void _glfwTerminateVulkan(void)
{
#if !defined(_GLFW_VULKAN_STATIC)
    if (_glfw.vk.handle)
        _glfw_dlclose(_glfw.vk.handle);
#endif
}