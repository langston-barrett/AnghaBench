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

/* Variables and functions */
 int /*<<< orphan*/  br_ec_p256_m15 ; 
 int /*<<< orphan*/  br_ecdsa_i15_sign_asn1 ; 
 int /*<<< orphan*/  br_ecdsa_i15_vrfy_asn1 ; 
 int /*<<< orphan*/  br_secp256r1 ; 
 int /*<<< orphan*/  test_speed_ecdsa_inner (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
test_speed_ecdsa_p256_m15(void)
{
	test_speed_ecdsa_inner("ECDSA m15 P-256",
		&br_ec_p256_m15, &br_secp256r1,
		&br_ecdsa_i15_sign_asn1,
		&br_ecdsa_i15_vrfy_asn1);
}