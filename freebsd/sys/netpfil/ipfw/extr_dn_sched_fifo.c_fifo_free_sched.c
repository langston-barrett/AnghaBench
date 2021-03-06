#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct dn_sch_inst {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  head; } ;
struct dn_queue {TYPE_1__ mq; } ;

/* Variables and functions */
 int /*<<< orphan*/  bzero (struct dn_queue*,int) ; 
 int /*<<< orphan*/  dn_free_pkts (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
fifo_free_sched(struct dn_sch_inst *si)
{
	struct dn_queue *q = (struct dn_queue *)(si + 1);
	dn_free_pkts(q->mq.head);
	bzero(q, sizeof(*q));
	return 0;
}