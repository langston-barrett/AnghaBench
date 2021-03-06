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
struct super_block {int dummy; } ;
struct ext4_group_desc {int /*<<< orphan*/  bg_itable_unused_hi; int /*<<< orphan*/  bg_itable_unused; } ;
typedef  int __u32 ;

/* Variables and functions */
 scalar_t__ EXT4_DESC_SIZE (struct super_block*) ; 
 scalar_t__ EXT4_MIN_DESC_SIZE_64BIT ; 
 int le16_to_cpu (int /*<<< orphan*/ ) ; 

__u32 ext4_itable_unused_count(struct super_block *sb,
                               struct ext4_group_desc *bg)
{
    return le16_to_cpu(bg->bg_itable_unused) |
           (EXT4_DESC_SIZE(sb) >= EXT4_MIN_DESC_SIZE_64BIT ?
            (__u32)le16_to_cpu(bg->bg_itable_unused_hi) << 16 : 0);
}