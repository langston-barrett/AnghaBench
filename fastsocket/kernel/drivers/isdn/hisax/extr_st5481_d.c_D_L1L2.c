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
struct st5481_adapter {int /*<<< orphan*/  hisax_d_if; } ;
struct hisax_if {int /*<<< orphan*/  (* l1l2 ) (struct hisax_if*,int,void*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct hisax_if*,int,void*) ; 

__attribute__((used)) static inline void D_L1L2(struct st5481_adapter *adapter, int pr, void *arg)
{
	struct hisax_if *ifc = (struct hisax_if *) &adapter->hisax_d_if;

	ifc->l1l2(ifc, pr, arg);
}