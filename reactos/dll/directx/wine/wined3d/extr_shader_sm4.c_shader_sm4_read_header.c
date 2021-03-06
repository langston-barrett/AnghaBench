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
struct wined3d_shader_version {int dummy; } ;
struct wined3d_sm4_data {struct wined3d_shader_version shader_version; int /*<<< orphan*/ * start; } ;
typedef  int /*<<< orphan*/  DWORD ;

/* Variables and functions */

__attribute__((used)) static void shader_sm4_read_header(void *data, const DWORD **ptr, struct wined3d_shader_version *shader_version)
{
    struct wined3d_sm4_data *priv = data;

    *ptr = priv->start;
    *shader_version = priv->shader_version;
}