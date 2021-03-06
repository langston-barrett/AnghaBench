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
struct sock {int /*<<< orphan*/  sk_write_queue; } ;
struct TYPE_4__ {int /*<<< orphan*/  cork; } ;
struct TYPE_3__ {int /*<<< orphan*/  cork; } ;

/* Variables and functions */
 int /*<<< orphan*/  __ip6_flush_pending_frames (struct sock*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 TYPE_2__* inet6_sk (struct sock*) ; 
 TYPE_1__* inet_sk (struct sock*) ; 

void ip6_flush_pending_frames(struct sock *sk)
{
	__ip6_flush_pending_frames(sk, &sk->sk_write_queue,
				   &inet_sk(sk)->cork, &inet6_sk(sk)->cork);
}