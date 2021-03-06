#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct qlcnic_adapter {TYPE_2__* ahw; } ;
typedef  int /*<<< orphan*/  loff_t ;
struct TYPE_4__ {TYPE_1__* hw_ops; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* read_crb ) (struct qlcnic_adapter*,char*,int /*<<< orphan*/ ,size_t) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct qlcnic_adapter*,char*,int /*<<< orphan*/ ,size_t) ; 

__attribute__((used)) static inline void qlcnic_read_crb(struct qlcnic_adapter *adapter, char *buf,
				   loff_t offset, size_t size)
{
	adapter->ahw->hw_ops->read_crb(adapter, buf, offset, size);
}