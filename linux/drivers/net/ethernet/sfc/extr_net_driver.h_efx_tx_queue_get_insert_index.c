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
struct efx_tx_queue {unsigned int insert_count; unsigned int ptr_mask; } ;

/* Variables and functions */

__attribute__((used)) static inline unsigned int
efx_tx_queue_get_insert_index(const struct efx_tx_queue *tx_queue)
{
	return tx_queue->insert_count & tx_queue->ptr_mask;
}