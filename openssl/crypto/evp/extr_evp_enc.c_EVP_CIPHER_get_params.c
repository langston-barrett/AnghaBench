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
struct TYPE_3__ {int (* get_params ) (int /*<<< orphan*/ *) ;} ;
typedef  int /*<<< orphan*/  OSSL_PARAM ;
typedef  TYPE_1__ EVP_CIPHER ;

/* Variables and functions */
 int stub1 (int /*<<< orphan*/ *) ; 

int EVP_CIPHER_get_params(EVP_CIPHER *cipher, OSSL_PARAM params[])
{
    if (cipher != NULL && cipher->get_params != NULL)
        return cipher->get_params(params);
    return 0;
}