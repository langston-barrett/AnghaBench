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
struct mlx5_cq {int cons_index; int /*<<< orphan*/ * dbrec; } ;

/* Variables and functions */
 size_t MLX5_CQ_SET_CI ; 
 int /*<<< orphan*/  htobe32 (int) ; 

__attribute__((used)) static void update_cons_index(struct mlx5_cq *cq)
{
	cq->dbrec[MLX5_CQ_SET_CI] = htobe32(cq->cons_index & 0xffffff);
}