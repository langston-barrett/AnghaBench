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
typedef  int /*<<< orphan*/  fz_sha384 ;

/* Variables and functions */
 int /*<<< orphan*/  fz_sha512_final (int /*<<< orphan*/ *,unsigned char*) ; 

void fz_sha384_final(fz_sha384 *context, unsigned char digest[64])
{
	fz_sha512_final(context, digest);
}