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
typedef  int /*<<< orphan*/  u16 ;
struct mlxsw_sp_acl_bf {int /*<<< orphan*/  lock; int /*<<< orphan*/ * refcnt; } ;
struct mlxsw_sp_acl_atcam_region {int dummy; } ;
struct mlxsw_sp_acl_atcam_entry {int dummy; } ;
struct mlxsw_sp {int /*<<< orphan*/  core; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  MLXSW_REG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MLXSW_REG_PEABFE_LEN ; 
 int /*<<< orphan*/  kfree (char*) ; 
 char* kmalloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlxsw_reg_peabfe_pack (char*) ; 
 int /*<<< orphan*/  mlxsw_reg_peabfe_rec_pack (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlxsw_reg_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  mlxsw_sp_acl_bf_index_get (struct mlxsw_sp_acl_bf*,struct mlxsw_sp_acl_atcam_region*,struct mlxsw_sp_acl_atcam_entry*) ; 
 unsigned int mlxsw_sp_acl_bf_rule_count_index_get (struct mlxsw_sp_acl_bf*,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  peabfe ; 
 scalar_t__ refcount_dec_and_test (int /*<<< orphan*/ *) ; 

void
mlxsw_sp_acl_bf_entry_del(struct mlxsw_sp *mlxsw_sp,
			  struct mlxsw_sp_acl_bf *bf,
			  struct mlxsw_sp_acl_atcam_region *aregion,
			  unsigned int erp_bank,
			  struct mlxsw_sp_acl_atcam_entry *aentry)
{
	unsigned int rule_index;
	char *peabfe_pl;
	u16 bf_index;

	mutex_lock(&bf->lock);

	bf_index = mlxsw_sp_acl_bf_index_get(bf, aregion, aentry);
	rule_index = mlxsw_sp_acl_bf_rule_count_index_get(bf, erp_bank,
							  bf_index);

	if (refcount_dec_and_test(&bf->refcnt[rule_index])) {
		peabfe_pl = kmalloc(MLXSW_REG_PEABFE_LEN, GFP_KERNEL);
		if (!peabfe_pl)
			goto unlock;

		mlxsw_reg_peabfe_pack(peabfe_pl);
		mlxsw_reg_peabfe_rec_pack(peabfe_pl, 0, 0, erp_bank, bf_index);
		mlxsw_reg_write(mlxsw_sp->core, MLXSW_REG(peabfe), peabfe_pl);
		kfree(peabfe_pl);
	}

unlock:
	mutex_unlock(&bf->lock);
}