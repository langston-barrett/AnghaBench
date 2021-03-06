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
struct mlxsw_afk_key_info {scalar_t__ ref_count; } ;

/* Variables and functions */
 int /*<<< orphan*/  mlxsw_afk_key_info_destroy (struct mlxsw_afk_key_info*) ; 

void mlxsw_afk_key_info_put(struct mlxsw_afk_key_info *key_info)
{
	if (--key_info->ref_count)
		return;
	mlxsw_afk_key_info_destroy(key_info);
}