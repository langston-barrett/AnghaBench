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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  scalar_t__ uint64_t ;
struct TYPE_2__ {int /*<<< orphan*/ * begin; } ;
struct pt_encoder {TYPE_1__ config; int /*<<< orphan*/ * pos; } ;
typedef  scalar_t__ int64_t ;

/* Variables and functions */
 int pte_internal ; 
 int pte_invalid ; 

int pt_enc_get_offset(const struct pt_encoder *encoder, uint64_t *offset)
{
	const uint8_t *raw, *begin;

	if (!encoder || !offset)
		return -pte_invalid;

	/* The encoder is synchronized at all times. */
	raw = encoder->pos;
	if (!raw)
		return -pte_internal;

	begin = encoder->config.begin;
	if (!begin)
		return -pte_internal;

	*offset = (uint64_t) (int64_t) (raw - begin);
	return 0;
}