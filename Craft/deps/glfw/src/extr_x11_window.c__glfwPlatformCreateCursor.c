#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  handle; } ;
struct TYPE_5__ {TYPE_1__ x11; } ;
typedef  TYPE_2__ _GLFWcursor ;
typedef  int /*<<< orphan*/  GLFWimage ;

/* Variables and functions */
 int GL_FALSE ; 
 int GL_TRUE ; 
 int /*<<< orphan*/  _glfwCreateCursor (int /*<<< orphan*/  const*,int,int) ; 

int _glfwPlatformCreateCursor(_GLFWcursor* cursor,
                              const GLFWimage* image,
                              int xhot, int yhot)
{
    cursor->x11.handle = _glfwCreateCursor(image, xhot, yhot);
    if (!cursor->x11.handle)
        return GL_FALSE;

    return GL_TRUE;
}