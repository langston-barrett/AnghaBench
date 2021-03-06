#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct sock {int /*<<< orphan*/  sk_sleep; } ;
struct TYPE_4__ {TYPE_1__* ep; } ;
struct TYPE_3__ {int /*<<< orphan*/  asocs; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEFINE_WAIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TASK_INTERRUPTIBLE ; 
 int /*<<< orphan*/  current ; 
 int /*<<< orphan*/  finish_wait (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ list_empty (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  prepare_to_wait (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 long schedule_timeout (long) ; 
 int /*<<< orphan*/  sctp_lock_sock (struct sock*) ; 
 int /*<<< orphan*/  sctp_release_sock (struct sock*) ; 
 TYPE_2__* sctp_sk (struct sock*) ; 
 int /*<<< orphan*/  signal_pending (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wait ; 

__attribute__((used)) static void sctp_wait_for_close(struct sock *sk, long timeout)
{
	DEFINE_WAIT(wait);

	do {
		prepare_to_wait(sk->sk_sleep, &wait, TASK_INTERRUPTIBLE);
		if (list_empty(&sctp_sk(sk)->ep->asocs))
			break;
		sctp_release_sock(sk);
		timeout = schedule_timeout(timeout);
		sctp_lock_sock(sk);
	} while (!signal_pending(current) && timeout);

	finish_wait(sk->sk_sleep, &wait);
}