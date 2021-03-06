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
typedef  int /*<<< orphan*/ * vop_header ;
typedef  int u8 ;

/* Variables and functions */
 int __le32_to_cpu (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u8 vop_hsize(const vop_header *vh)
{
	return (__le32_to_cpu((*vh)[1]) >> 8) & 0xFF;
}