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
struct snd_pcm_substream {struct isight* private_data; } ;
struct snd_pcm_hw_params {int dummy; } ;
struct isight {int /*<<< orphan*/  pcm_active; } ;

/* Variables and functions */
 int /*<<< orphan*/  WRITE_ONCE (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  params_buffer_bytes (struct snd_pcm_hw_params*) ; 
 int snd_pcm_lib_alloc_vmalloc_buffer (struct snd_pcm_substream*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int isight_hw_params(struct snd_pcm_substream *substream,
			    struct snd_pcm_hw_params *hw_params)
{
	struct isight *isight = substream->private_data;
	int err;

	err = snd_pcm_lib_alloc_vmalloc_buffer(substream,
					       params_buffer_bytes(hw_params));
	if (err < 0)
		return err;

	WRITE_ONCE(isight->pcm_active, true);

	return 0;
}