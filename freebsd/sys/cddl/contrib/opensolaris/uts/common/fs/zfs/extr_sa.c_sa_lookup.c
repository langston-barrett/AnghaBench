#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
struct TYPE_7__ {int /*<<< orphan*/  sa_lock; } ;
typedef  TYPE_1__ sa_handle_t ;
struct TYPE_8__ {int /*<<< orphan*/ * sa_data_func; int /*<<< orphan*/  sa_length; void* sa_data; int /*<<< orphan*/  sa_attr; } ;
typedef  TYPE_2__ sa_bulk_attr_t ;
typedef  int /*<<< orphan*/  sa_attr_type_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (TYPE_1__*) ; 
 int /*<<< orphan*/  mutex_enter (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_exit (int /*<<< orphan*/ *) ; 
 int sa_lookup_impl (TYPE_1__*,TYPE_2__*,int) ; 

int
sa_lookup(sa_handle_t *hdl, sa_attr_type_t attr, void *buf, uint32_t buflen)
{
	int error;
	sa_bulk_attr_t bulk;

	bulk.sa_attr = attr;
	bulk.sa_data = buf;
	bulk.sa_length = buflen;
	bulk.sa_data_func = NULL;

	ASSERT(hdl);
	mutex_enter(&hdl->sa_lock);
	error = sa_lookup_impl(hdl, &bulk, 1);
	mutex_exit(&hdl->sa_lock);
	return (error);
}