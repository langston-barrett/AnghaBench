#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {int /*<<< orphan*/  send_list; } ;
typedef  TYPE_1__ isc_task_t ;
struct TYPE_12__ {int attributes; TYPE_1__* ev_sender; } ;
typedef  TYPE_2__ isc_socketevent_t ;
typedef  TYPE_1__ isc_socket_t ;
typedef  int /*<<< orphan*/  isc_event_t ;

/* Variables and functions */
 int /*<<< orphan*/  CONSISTENT (TYPE_1__*) ; 
 int /*<<< orphan*/  INSIST (int) ; 
 scalar_t__ ISC_LINK_LINKED (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ISC_LIST_DEQUEUE (int /*<<< orphan*/ ,TYPE_2__*,int /*<<< orphan*/ ) ; 
 int ISC_SOCKEVENTATTR_ATTACHED ; 
 int /*<<< orphan*/  ev_link ; 
 int /*<<< orphan*/  isc_task_send (TYPE_1__*,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  isc_task_sendanddetach (TYPE_1__**,int /*<<< orphan*/ **) ; 

__attribute__((used)) static void
send_senddone_event(isc_socket_t *sock, isc_socketevent_t **dev) {
	isc_task_t *task;

	INSIST(dev != NULL && *dev != NULL);

	task = (*dev)->ev_sender;
	(*dev)->ev_sender = sock;

	if (ISC_LINK_LINKED(*dev, ev_link))
		ISC_LIST_DEQUEUE(sock->send_list, *dev, ev_link);

	if (((*dev)->attributes & ISC_SOCKEVENTATTR_ATTACHED)
	    == ISC_SOCKEVENTATTR_ATTACHED)
		isc_task_sendanddetach(&task, (isc_event_t **)dev);
	else
		isc_task_send(task, (isc_event_t **)dev);

	CONSISTENT(sock);
}