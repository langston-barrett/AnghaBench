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
struct snd_pcm_substream {struct snd_pcm_runtime* runtime; } ;
struct snd_pcm_runtime {struct aaci_runtime* private_data; } ;
struct aaci_runtime {scalar_t__ start; scalar_t__ ptr; } ;
typedef  scalar_t__ ssize_t ;
typedef  int /*<<< orphan*/  snd_pcm_uframes_t ;

/* Variables and functions */
 int /*<<< orphan*/  bytes_to_frames (struct snd_pcm_runtime*,scalar_t__) ; 

__attribute__((used)) static snd_pcm_uframes_t aaci_pcm_pointer(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct aaci_runtime *aacirun = runtime->private_data;
	ssize_t bytes = aacirun->ptr - aacirun->start;

	return bytes_to_frames(runtime, bytes);
}