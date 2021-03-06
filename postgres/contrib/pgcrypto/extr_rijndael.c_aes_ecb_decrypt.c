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
typedef  int /*<<< orphan*/  uint8 ;
typedef  int /*<<< orphan*/  uint32 ;
typedef  int /*<<< orphan*/  rijndael_ctx ;

/* Variables and functions */
 int /*<<< orphan*/  rijndael_decrypt (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

void
aes_ecb_decrypt(rijndael_ctx *ctx, uint8 *data, unsigned len)
{
	unsigned	bs = 16;
	uint32	   *d;

	while (len >= bs)
	{
		d = (uint32 *) data;
		rijndael_decrypt(ctx, d, d);

		len -= bs;
		data += bs;
	}
}