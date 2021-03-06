#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {TYPE_1__* pmeth; } ;
struct TYPE_5__ {int (* ctrl ) (TYPE_2__*,int,size_t,void*) ;} ;
typedef  TYPE_2__ EVP_PKEY_CTX ;

/* Variables and functions */
 size_t INT_MAX ; 
 size_t strlen (char const*) ; 
 int stub1 (TYPE_2__*,int,size_t,void*) ; 

int EVP_PKEY_CTX_str2ctrl(EVP_PKEY_CTX *ctx, int cmd, const char *str)
{
    size_t len;

    len = strlen(str);
    if (len > INT_MAX)
        return -1;
    return ctx->pmeth->ctrl(ctx, cmd, len, (void *)str);
}