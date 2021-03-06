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
struct snd_rawmidi_substream {TYPE_1__* rmidi; } ;
struct snd_ca_midi {int midi_mode; int /*<<< orphan*/  open_lock; int /*<<< orphan*/  reset; int /*<<< orphan*/ * substream_input; int /*<<< orphan*/  rx_enable; int /*<<< orphan*/  (* interrupt_disable ) (struct snd_ca_midi*,int /*<<< orphan*/ ) ;int /*<<< orphan*/  dev_id; } ;
struct TYPE_2__ {struct snd_ca_midi* private_data; } ;

/* Variables and functions */
 int CA_MIDI_MODE_INPUT ; 
 int CA_MIDI_MODE_OUTPUT ; 
 int ENXIO ; 
 int /*<<< orphan*/  ca_midi_cmd (struct snd_ca_midi*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ snd_BUG_ON (int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  stub1 (struct snd_ca_midi*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ca_midi_input_close(struct snd_rawmidi_substream *substream)
{
	struct snd_ca_midi *midi = substream->rmidi->private_data;
	unsigned long flags;

	if (snd_BUG_ON(!midi->dev_id))
		return -ENXIO;
	spin_lock_irqsave(&midi->open_lock, flags);
	midi->interrupt_disable(midi,midi->rx_enable);
	midi->midi_mode &= ~CA_MIDI_MODE_INPUT;
	midi->substream_input = NULL;
	if (!(midi->midi_mode & CA_MIDI_MODE_OUTPUT)) {
		spin_unlock_irqrestore(&midi->open_lock, flags);
		ca_midi_cmd(midi, midi->reset, 0);
	} else {
		spin_unlock_irqrestore(&midi->open_lock, flags);
	}
	return 0;
}