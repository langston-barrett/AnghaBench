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
struct mm_struct {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CAP_SYS_ADMIN ; 
 int /*<<< orphan*/  SECURITY_CAP_NOAUDIT ; 
 int __vm_enough_memory (struct mm_struct*,long,int) ; 
 scalar_t__ cap_capable (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  current ; 
 int /*<<< orphan*/  current_cred () ; 

int cap_vm_enough_memory(struct mm_struct *mm, long pages)
{
	int cap_sys_admin = 0;

	if (cap_capable(current, current_cred(), CAP_SYS_ADMIN,
			SECURITY_CAP_NOAUDIT) == 0)
		cap_sys_admin = 1;
	return __vm_enough_memory(mm, pages, cap_sys_admin);
}