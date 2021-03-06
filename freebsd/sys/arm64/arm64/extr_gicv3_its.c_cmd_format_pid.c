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
typedef  int uint64_t ;
typedef  scalar_t__ uint32_t ;
struct its_cmd {int /*<<< orphan*/ * cmd_dword; } ;

/* Variables and functions */
 int CMD_PID_MASK ; 
 int CMD_PID_SHIFT ; 
 int /*<<< orphan*/  htole64 (int) ; 

__attribute__((used)) static __inline void
cmd_format_pid(struct its_cmd *cmd, uint32_t pid)
{
	/* Physical ID field: DW1 [63:32] */
	cmd->cmd_dword[1] &= htole64(~CMD_PID_MASK);
	cmd->cmd_dword[1] |= htole64((uint64_t)pid << CMD_PID_SHIFT);
}