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
typedef  int /*<<< orphan*/  PROV_AES_OCB_CTX ;

/* Variables and functions */
 int /*<<< orphan*/  OPENSSL_clear_free (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  aes_generic_ocb_cleanup (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void aes_ocb_freectx(void *vctx)
{
    PROV_AES_OCB_CTX *ctx = (PROV_AES_OCB_CTX *)vctx;

    if (ctx != NULL) {
        aes_generic_ocb_cleanup(ctx);
        OPENSSL_clear_free(ctx,  sizeof(*ctx));
    }
}