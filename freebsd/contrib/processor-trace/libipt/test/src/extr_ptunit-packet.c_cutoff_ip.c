#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct ptunit_result {int dummy; } ;
struct TYPE_10__ {scalar_t__ end; } ;
struct TYPE_11__ {TYPE_3__ config; } ;
struct TYPE_13__ {scalar_t__ pos; } ;
struct packet_fixture {TYPE_5__* packet; TYPE_4__ decoder; TYPE_6__ encoder; } ;
typedef  enum pt_packet_type { ____Placeholder_pt_packet_type } pt_packet_type ;
struct TYPE_8__ {int /*<<< orphan*/  ipc; } ;
struct TYPE_9__ {TYPE_1__ ip; } ;
struct TYPE_12__ {int type; TYPE_2__ payload; } ;

/* Variables and functions */
 int pt_enc_next (TYPE_6__*,TYPE_5__*) ; 
 int /*<<< orphan*/  pt_ipc_sext_48 ; 
 int pt_pkt_next (TYPE_4__*,TYPE_5__*,int) ; 
 int /*<<< orphan*/  pte_eos ; 
 int /*<<< orphan*/  ptu_int_eq (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ptu_int_gt (int,int /*<<< orphan*/ ) ; 
 struct ptunit_result ptu_passed () ; 

__attribute__((used)) static struct ptunit_result cutoff_ip(struct packet_fixture *pfix,
				      enum pt_packet_type type)
{
	int size;

	pfix->packet[0].type = type;
	pfix->packet[0].payload.ip.ipc = pt_ipc_sext_48;

	size = pt_enc_next(&pfix->encoder, &pfix->packet[0]);
	ptu_int_gt(size, 0);

	pfix->decoder.config.end = pfix->encoder.pos - 1;

	size = pt_pkt_next(&pfix->decoder, &pfix->packet[1],
			   sizeof(pfix->packet[1]));
	ptu_int_eq(size, -pte_eos);

	return ptu_passed();
}