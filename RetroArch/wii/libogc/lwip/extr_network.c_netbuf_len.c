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
typedef  int /*<<< orphan*/  u16 ;
struct netbuf {TYPE_1__* p; } ;
struct TYPE_2__ {int /*<<< orphan*/  tot_len; } ;

/* Variables and functions */

__attribute__((used)) static __inline__ u16 netbuf_len(struct netbuf *buf)
{
	return ((buf && buf->p)?buf->p->tot_len:0);
}