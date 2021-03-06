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
struct TYPE_3__ {int /*<<< orphan*/  emaillen; int /*<<< orphan*/  email; } ;
typedef  TYPE_1__ X509_VERIFY_PARAM ;

/* Variables and functions */
 int int_x509_param_set1 (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char const*,size_t) ; 

int X509_VERIFY_PARAM_set1_email(X509_VERIFY_PARAM *param,
                                 const char *email, size_t emaillen)
{
    return int_x509_param_set1(&param->email, &param->emaillen,
                               email, emaillen);
}