#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {scalar_t__ offset; TYPE_1__* data; } ;
typedef  TYPE_2__ network_packet ;
typedef  scalar_t__ gsize ;
struct TYPE_4__ {scalar_t__ len; } ;

/* Variables and functions */

int network_mysqld_proto_skip(network_packet *packet, gsize size) {
	if (packet->offset + size > packet->data->len) return -1;
	
	packet->offset += size;

	return 0;
}