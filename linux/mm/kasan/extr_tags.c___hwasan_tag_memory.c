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
typedef  int /*<<< orphan*/  u8 ;

/* Variables and functions */
 int /*<<< orphan*/  kasan_poison_shadow (void*,unsigned long,int /*<<< orphan*/ ) ; 

void __hwasan_tag_memory(unsigned long addr, u8 tag, unsigned long size)
{
	kasan_poison_shadow((void *)addr, size, tag);
}