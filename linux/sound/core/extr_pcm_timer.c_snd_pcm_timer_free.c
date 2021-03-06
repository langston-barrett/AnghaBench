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
struct snd_timer {struct snd_pcm_substream* private_data; } ;
struct snd_pcm_substream {int /*<<< orphan*/ * timer; } ;

/* Variables and functions */

__attribute__((used)) static void snd_pcm_timer_free(struct snd_timer *timer)
{
	struct snd_pcm_substream *substream = timer->private_data;
	substream->timer = NULL;
}