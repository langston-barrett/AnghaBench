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
struct grub_nilfs2_data {int dummy; } ;
typedef  int grub_uint32_t ;

/* Variables and functions */
 int grub_nilfs2_blocks_per_desc_block (struct grub_nilfs2_data*,unsigned long) ; 
 unsigned long grub_nilfs2_palloc_groups_per_desc_block (struct grub_nilfs2_data*) ; 

__attribute__((used)) static inline grub_uint32_t
grub_nilfs2_palloc_desc_block_offset (struct grub_nilfs2_data *data,
				      unsigned long group,
				      unsigned long entry_size)
{
  grub_uint32_t desc_block =
    group / grub_nilfs2_palloc_groups_per_desc_block (data);
  return desc_block * grub_nilfs2_blocks_per_desc_block (data, entry_size);
}