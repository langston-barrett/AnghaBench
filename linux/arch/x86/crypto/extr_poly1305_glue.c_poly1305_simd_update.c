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
typedef  int /*<<< orphan*/  u8 ;
struct shash_desc {int dummy; } ;
struct poly1305_desc_ctx {unsigned int buflen; int /*<<< orphan*/  const* buf; } ;

/* Variables and functions */
 unsigned int POLY1305_BLOCK_SIZE ; 
 int crypto_poly1305_update (struct shash_desc*,int /*<<< orphan*/  const*,unsigned int) ; 
 int /*<<< orphan*/  crypto_simd_usable () ; 
 int /*<<< orphan*/  kernel_fpu_begin () ; 
 int /*<<< orphan*/  kernel_fpu_end () ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,unsigned int) ; 
 unsigned int min (unsigned int,unsigned int) ; 
 unsigned int poly1305_simd_blocks (struct poly1305_desc_ctx*,int /*<<< orphan*/  const*,unsigned int) ; 
 struct poly1305_desc_ctx* shash_desc_ctx (struct shash_desc*) ; 
 scalar_t__ unlikely (unsigned int) ; 

__attribute__((used)) static int poly1305_simd_update(struct shash_desc *desc,
				const u8 *src, unsigned int srclen)
{
	struct poly1305_desc_ctx *dctx = shash_desc_ctx(desc);
	unsigned int bytes;

	/* kernel_fpu_begin/end is costly, use fallback for small updates */
	if (srclen <= 288 || !crypto_simd_usable())
		return crypto_poly1305_update(desc, src, srclen);

	kernel_fpu_begin();

	if (unlikely(dctx->buflen)) {
		bytes = min(srclen, POLY1305_BLOCK_SIZE - dctx->buflen);
		memcpy(dctx->buf + dctx->buflen, src, bytes);
		src += bytes;
		srclen -= bytes;
		dctx->buflen += bytes;

		if (dctx->buflen == POLY1305_BLOCK_SIZE) {
			poly1305_simd_blocks(dctx, dctx->buf,
					     POLY1305_BLOCK_SIZE);
			dctx->buflen = 0;
		}
	}

	if (likely(srclen >= POLY1305_BLOCK_SIZE)) {
		bytes = poly1305_simd_blocks(dctx, src, srclen);
		src += srclen - bytes;
		srclen = bytes;
	}

	kernel_fpu_end();

	if (unlikely(srclen)) {
		dctx->buflen = srclen;
		memcpy(dctx->buf, src, srclen);
	}

	return 0;
}