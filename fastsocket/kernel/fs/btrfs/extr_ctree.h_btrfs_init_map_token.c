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
struct btrfs_map_token {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  memset (struct btrfs_map_token*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline void btrfs_init_map_token (struct btrfs_map_token *token)
{
	memset(token, 0, sizeof(*token));
}