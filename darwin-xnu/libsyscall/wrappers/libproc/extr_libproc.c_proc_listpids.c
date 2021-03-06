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
typedef  int /*<<< orphan*/  uint64_t ;
typedef  scalar_t__ uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 scalar_t__ PROC_ALL_PIDS ; 
 int /*<<< orphan*/  PROC_INFO_CALL_LISTPIDS ; 
 scalar_t__ PROC_PPID_ONLY ; 
 int __proc_info (int /*<<< orphan*/ ,scalar_t__,scalar_t__,int /*<<< orphan*/ ,void*,int) ; 
 int /*<<< orphan*/  errno ; 

int 
proc_listpids(uint32_t type, uint32_t typeinfo, void *buffer, int buffersize) 
{
	int retval;
	
	if ((type >= PROC_ALL_PIDS) || (type <= PROC_PPID_ONLY)) {
		if ((retval = __proc_info(PROC_INFO_CALL_LISTPIDS, type, typeinfo,(uint64_t)0, buffer, buffersize)) == -1)
			return(0);
	} else {
		errno = EINVAL;
		retval = 0;
	}
	return(retval);
}