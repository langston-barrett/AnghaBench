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
struct snd_pcm_substream {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int ct_pcm_capture_close(struct snd_pcm_substream *substream)
{
	/* The ct_atc_pcm object will be freed by runtime->private_free */
	/* TODO: Notify mixer inactive. */
	return 0;
}