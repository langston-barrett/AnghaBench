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
typedef  int /*<<< orphan*/  u8 ;
struct mlxfw_mfa2_file {TYPE_1__* fw; } ;
struct TYPE_2__ {int datasize; int /*<<< orphan*/ * data; } ;

/* Variables and functions */

__attribute__((used)) static inline bool mlxfw_mfa2_valid_ptr(const struct mlxfw_mfa2_file *mfa2_file,
					const u8 *ptr)
{
	const u8 *valid_to = (const u8 *) mfa2_file->fw->data + mfa2_file->fw->datasize;
	const u8 *valid_from = mfa2_file->fw->data;

	return ptr > valid_from && ptr < valid_to;
}