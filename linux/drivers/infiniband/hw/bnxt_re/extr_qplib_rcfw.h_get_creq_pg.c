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
typedef  int u32 ;

/* Variables and functions */
 int BNXT_QPLIB_CREQE_CNT_PER_PG ; 
 int MAX_CREQ_IDX_PER_PG ; 

__attribute__((used)) static inline u32 get_creq_pg(u32 val)
{
	return (val & ~MAX_CREQ_IDX_PER_PG) / BNXT_QPLIB_CREQE_CNT_PER_PG;
}