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
struct bfa_msgq_cmdq {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  bfa_msgq_cmdq_dbell (struct bfa_msgq_cmdq*) ; 

__attribute__((used)) static void
cmdq_sm_dbell_wait_entry(struct bfa_msgq_cmdq *cmdq)
{
	bfa_msgq_cmdq_dbell(cmdq);
}