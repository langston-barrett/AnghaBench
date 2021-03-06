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
struct extended_attribute {int namelen; } ;
typedef  int /*<<< orphan*/  secno ;
typedef  int /*<<< orphan*/  __le32 ;

/* Variables and functions */
 int /*<<< orphan*/  get_unaligned (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  le32_to_cpu (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline secno ea_sec(struct extended_attribute *ea)
{
	return le32_to_cpu(get_unaligned((__le32 *)((char *)ea + 9 + ea->namelen)));
}