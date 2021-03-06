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
struct circ_buf {scalar_t__ tail; scalar_t__ head; } ;

/* Variables and functions */

__attribute__((used)) static void serial_buf_clear(struct circ_buf *cb)
{
	cb->head = cb->tail = 0;
}