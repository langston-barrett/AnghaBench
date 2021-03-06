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
struct node {int dummy; } ;
struct boot_info {int dummy; } ;

/* Variables and functions */
 struct boot_info* build_boot_info (int /*<<< orphan*/ *,struct node*,int /*<<< orphan*/ ) ; 
 struct node* name_node (struct node*,char*,int /*<<< orphan*/ *) ; 
 struct node* read_fstree (char const*) ; 

struct boot_info *dt_from_fs(const char *dirname)
{
	struct node *tree;

	tree = read_fstree(dirname);
	tree = name_node(tree, "", NULL);

	return build_boot_info(NULL, tree, 0);
}