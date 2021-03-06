#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct mbuf {int m_flags; } ;
struct ifnet {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/ * pb_next; struct ifnet* pb_ifp; struct mbuf* pb_mbuf; int /*<<< orphan*/  pb_type; } ;
typedef  TYPE_1__ pbuf_t ;

/* Variables and functions */
 int M_PKTHDR ; 
 int /*<<< orphan*/  PBUF_TYPE_MBUF ; 
 int /*<<< orphan*/  VERIFY (int) ; 
 int /*<<< orphan*/  pbuf_sync (TYPE_1__*) ; 

void
pbuf_init_mbuf(pbuf_t *pbuf, struct mbuf *m, struct ifnet *ifp)
{

	VERIFY((m->m_flags & M_PKTHDR) != 0);

	pbuf->pb_type = PBUF_TYPE_MBUF;
	pbuf->pb_mbuf = m;
	pbuf->pb_ifp = ifp;
	pbuf->pb_next = NULL;
	pbuf_sync(pbuf);
}