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
struct msg_security_struct {int dummy; } ;
struct msg_msg {struct msg_security_struct* security; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct msg_security_struct*) ; 

__attribute__((used)) static void msg_msg_free_security(struct msg_msg *msg)
{
	struct msg_security_struct *msec = msg->security;

	msg->security = NULL;
	kfree(msec);
}