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
struct test {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  EPERM ; 
 int /*<<< orphan*/  UID_OTHER ; 
 int /*<<< orphan*/  expect (char*,int,int,int /*<<< orphan*/ ) ; 
 int setresuid (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
priv_cred_setresuid(int asroot, int injail, struct test *test)
{
	int error;

	error = setresuid(UID_OTHER, UID_OTHER, UID_OTHER);
	if (asroot && injail)
		expect("priv_setresuid(asroot, injail)", error, 0, 0);
	if (asroot && !injail)
		expect("priv_setresuid(asroot, !injail)", error, 0, 0);
	if (!asroot && injail)
		expect("priv_setresuid(!asroot, injail)", error, -1, EPERM);
	if (!asroot && !injail)
		expect("priv_setresuid(!asroot, !injail)", error, -1, EPERM);
}