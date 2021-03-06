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
 int CUDBG_QTYPE_CRYPTO_FLQ ; 
 int CUDBG_QTYPE_ISCSIT_FLQ ; 
 int CUDBG_QTYPE_ISCSI_FLQ ; 
 int CUDBG_QTYPE_RDMA_FLQ ; 
 int CUDBG_QTYPE_TLS_FLQ ; 
 int CUDBG_QTYPE_UNKNOWN ; 
#define  CXGB4_ULD_CRYPTO 132 
#define  CXGB4_ULD_ISCSI 131 
#define  CXGB4_ULD_ISCSIT 130 
#define  CXGB4_ULD_RDMA 129 
#define  CXGB4_ULD_TLS 128 

__attribute__((used)) static inline u32 cudbg_uld_flq_to_qtype(u32 uld)
{
	switch (uld) {
	case CXGB4_ULD_RDMA:
		return CUDBG_QTYPE_RDMA_FLQ;
	case CXGB4_ULD_ISCSI:
		return CUDBG_QTYPE_ISCSI_FLQ;
	case CXGB4_ULD_ISCSIT:
		return CUDBG_QTYPE_ISCSIT_FLQ;
	case CXGB4_ULD_CRYPTO:
		return CUDBG_QTYPE_CRYPTO_FLQ;
	case CXGB4_ULD_TLS:
		return CUDBG_QTYPE_TLS_FLQ;
	}

	return CUDBG_QTYPE_UNKNOWN;
}