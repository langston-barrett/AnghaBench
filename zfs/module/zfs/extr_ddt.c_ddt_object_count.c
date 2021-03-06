#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint64_t ;
typedef  enum ddt_type { ____Placeholder_ddt_type } ddt_type ;
typedef  enum ddt_class { ____Placeholder_ddt_class } ddt_class ;
struct TYPE_5__ {int /*<<< orphan*/ ** ddt_object; int /*<<< orphan*/  ddt_os; } ;
typedef  TYPE_1__ ddt_t ;
struct TYPE_6__ {int (* ddt_op_count ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ddt_object_exists (TYPE_1__*,int,int) ; 
 TYPE_2__** ddt_ops ; 
 int stub1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

int
ddt_object_count(ddt_t *ddt, enum ddt_type type, enum ddt_class class,
    uint64_t *count)
{
	ASSERT(ddt_object_exists(ddt, type, class));

	return (ddt_ops[type]->ddt_op_count(ddt->ddt_os,
	    ddt->ddt_object[type][class], count));
}