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
struct ff_packet {int /*<<< orphan*/  base; int /*<<< orphan*/ * clock; } ;
struct ff_decoder {int /*<<< orphan*/ * clock; } ;

/* Variables and functions */
 int /*<<< orphan*/  av_free_packet (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ff_clock_release (int /*<<< orphan*/ **) ; 

__attribute__((used)) static bool handle_reset_packet(struct ff_decoder *decoder,
                                struct ff_packet *packet)
{
	if (decoder->clock != NULL)
		ff_clock_release(&decoder->clock);
	decoder->clock = packet->clock;
	av_free_packet(&packet->base);

	return true;
}