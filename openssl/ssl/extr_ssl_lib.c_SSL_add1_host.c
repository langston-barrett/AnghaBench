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
struct TYPE_3__ {int /*<<< orphan*/  param; } ;
typedef  TYPE_1__ SSL ;

/* Variables and functions */
 int X509_VERIFY_PARAM_add1_host (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 

int SSL_add1_host(SSL *s, const char *hostname)
{
    return X509_VERIFY_PARAM_add1_host(s->param, hostname, 0);
}