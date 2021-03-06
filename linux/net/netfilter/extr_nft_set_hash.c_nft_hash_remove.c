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
struct nft_set_elem {struct nft_hash_elem* priv; } ;
struct nft_set {int dummy; } ;
struct nft_hash_elem {int /*<<< orphan*/  node; } ;
struct net {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  hlist_del_rcu (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void nft_hash_remove(const struct net *net,
			    const struct nft_set *set,
			    const struct nft_set_elem *elem)
{
	struct nft_hash_elem *he = elem->priv;

	hlist_del_rcu(&he->node);
}