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
typedef  int /*<<< orphan*/  uint8_t ;
struct ib_cm_id {int dummy; } ;
typedef  enum ib_cm_rej_reason { ____Placeholder_ib_cm_rej_reason } ib_cm_rej_reason ;

/* Variables and functions */
 int /*<<< orphan*/  IB_USER_CM_CMD_SEND_REJ ; 
 int cm_send_status (struct ib_cm_id*,int /*<<< orphan*/ ,int,void*,int /*<<< orphan*/ ,void*,int /*<<< orphan*/ ) ; 

int ib_cm_send_rej(struct ib_cm_id *cm_id,
		   enum ib_cm_rej_reason reason,
		   void *ari,
		   uint8_t ari_length,
		   void *private_data,
		   uint8_t private_data_len)
{
	return cm_send_status(cm_id, IB_USER_CM_CMD_SEND_REJ, reason, 
			      ari, ari_length,
			      private_data, private_data_len);
}