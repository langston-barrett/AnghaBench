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
typedef  int /*<<< orphan*/  br_ssl_engine_context ;

/* Variables and functions */
 int /*<<< orphan*/  br_rsa_pkcs1_vrfy_get_default () ; 
 int /*<<< orphan*/  br_ssl_engine_set_rsavrfy (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void
br_ssl_engine_set_default_rsavrfy(br_ssl_engine_context *cc)
{
	br_ssl_engine_set_rsavrfy(cc, br_rsa_pkcs1_vrfy_get_default());
}