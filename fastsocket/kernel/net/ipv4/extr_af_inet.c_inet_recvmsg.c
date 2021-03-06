#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct socket {struct sock* sk; } ;
struct sock {TYPE_1__* sk_prot; } ;
struct msghdr {int msg_namelen; } ;
struct kiocb {int dummy; } ;
struct TYPE_2__ {int (* recvmsg ) (struct kiocb*,struct sock*,struct msghdr*,size_t,int,int,int*) ;} ;

/* Variables and functions */
 int MSG_DONTWAIT ; 
 int /*<<< orphan*/  inet_sock_cpu_or_flow_record (struct sock*) ; 
 int stub1 (struct kiocb*,struct sock*,struct msghdr*,size_t,int,int,int*) ; 

int inet_recvmsg(struct kiocb *iocb, struct socket *sock, struct msghdr *msg,
		 size_t size, int flags)
{
	struct sock *sk = sock->sk;
	int addr_len = 0;
	int err;

	inet_sock_cpu_or_flow_record(sk);

	err = sk->sk_prot->recvmsg(iocb, sk, msg, size, flags & MSG_DONTWAIT,
				   flags & ~MSG_DONTWAIT, &addr_len);
	if (err >= 0)
		msg->msg_namelen = addr_len;
	return err;
}