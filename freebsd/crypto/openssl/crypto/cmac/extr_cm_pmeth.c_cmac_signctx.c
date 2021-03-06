#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  data; } ;
typedef  TYPE_1__ EVP_PKEY_CTX ;
typedef  int /*<<< orphan*/  EVP_MD_CTX ;

/* Variables and functions */
 int CMAC_Final (int /*<<< orphan*/ ,unsigned char*,size_t*) ; 

__attribute__((used)) static int cmac_signctx(EVP_PKEY_CTX *ctx, unsigned char *sig, size_t *siglen,
                        EVP_MD_CTX *mctx)
{
    return CMAC_Final(ctx->data, sig, siglen);
}