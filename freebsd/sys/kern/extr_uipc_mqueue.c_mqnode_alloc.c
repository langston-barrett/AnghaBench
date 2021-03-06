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
struct mqfs_node {int dummy; } ;

/* Variables and functions */
 int M_WAITOK ; 
 int M_ZERO ; 
 int /*<<< orphan*/  mqnode_zone ; 
 struct mqfs_node* uma_zalloc (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static __inline struct mqfs_node *
mqnode_alloc(void)
{
	return uma_zalloc(mqnode_zone, M_WAITOK | M_ZERO);
}