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
struct ucred {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MAC_CHECK_PROBE2 (int /*<<< orphan*/ ,int,struct ucred*,int) ; 
 int /*<<< orphan*/  MAC_POLICY_CHECK_NOSLEEP (int /*<<< orphan*/ ,struct ucred*,int) ; 
 int /*<<< orphan*/  system_check_auditon ; 

int
mac_system_check_auditon(struct ucred *cred, int cmd)
{
	int error;

	MAC_POLICY_CHECK_NOSLEEP(system_check_auditon, cred, cmd);
	MAC_CHECK_PROBE2(system_check_auditon, error, cred, cmd);

	return (error);
}