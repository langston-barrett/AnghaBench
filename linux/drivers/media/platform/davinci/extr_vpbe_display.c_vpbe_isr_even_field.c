#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct vpbe_layer {TYPE_2__* next_frm; TYPE_2__* cur_frm; } ;
struct vpbe_display {int dummy; } ;
struct TYPE_6__ {int /*<<< orphan*/  timestamp; } ;
struct TYPE_4__ {TYPE_3__ vb2_buf; } ;
struct TYPE_5__ {TYPE_1__ vb; } ;

/* Variables and functions */
 int /*<<< orphan*/  VB2_BUF_STATE_DONE ; 
 int /*<<< orphan*/  ktime_get_ns () ; 
 int /*<<< orphan*/  vb2_buffer_done (TYPE_3__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void vpbe_isr_even_field(struct vpbe_display *disp_obj,
				struct vpbe_layer *layer)
{
	if (layer->cur_frm == layer->next_frm)
		return;

	layer->cur_frm->vb.vb2_buf.timestamp = ktime_get_ns();
	vb2_buffer_done(&layer->cur_frm->vb.vb2_buf, VB2_BUF_STATE_DONE);
	/* Make cur_frm pointing to next_frm */
	layer->cur_frm = layer->next_frm;
}