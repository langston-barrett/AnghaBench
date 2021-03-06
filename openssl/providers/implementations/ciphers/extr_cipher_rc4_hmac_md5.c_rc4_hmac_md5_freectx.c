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
typedef  int /*<<< orphan*/  PROV_RC4_HMAC_MD5_CTX ;

/* Variables and functions */
 int /*<<< orphan*/  OPENSSL_clear_free (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void rc4_hmac_md5_freectx(void *vctx)
{
    PROV_RC4_HMAC_MD5_CTX *ctx = (PROV_RC4_HMAC_MD5_CTX *)vctx;

    OPENSSL_clear_free(ctx,  sizeof(*ctx));
}