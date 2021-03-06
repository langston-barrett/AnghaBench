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
struct snd_rawmidi_substream {int bytes; struct snd_rawmidi_runtime* runtime; } ;
struct snd_rawmidi_runtime {int avail; int buffer_size; int hw_ptr; int /*<<< orphan*/  lock; int /*<<< orphan*/  sleep; scalar_t__ drain; int /*<<< orphan*/ * buffer; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  snd_BUG_ON (int) ; 
 int /*<<< orphan*/  snd_printd (char*) ; 
 scalar_t__ snd_rawmidi_ready (struct snd_rawmidi_substream*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

int snd_rawmidi_transmit_ack(struct snd_rawmidi_substream *substream, int count)
{
	unsigned long flags;
	struct snd_rawmidi_runtime *runtime = substream->runtime;

	if (runtime->buffer == NULL) {
		snd_printd("snd_rawmidi_transmit_ack: output is not active!!!\n");
		return -EINVAL;
	}
	spin_lock_irqsave(&runtime->lock, flags);
	snd_BUG_ON(runtime->avail + count > runtime->buffer_size);
	runtime->hw_ptr += count;
	runtime->hw_ptr %= runtime->buffer_size;
	runtime->avail += count;
	substream->bytes += count;
	if (count > 0) {
		if (runtime->drain || snd_rawmidi_ready(substream))
			wake_up(&runtime->sleep);
	}
	spin_unlock_irqrestore(&runtime->lock, flags);
	return count;
}