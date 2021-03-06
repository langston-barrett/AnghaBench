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
typedef  int /*<<< orphan*/  u8 ;
struct r8152 {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MCU_TYPE_PLA ; 
 int /*<<< orphan*/  PLA_PHYSTATUS ; 
 int /*<<< orphan*/  ocp_read_byte (struct r8152*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u8 rtl8152_get_speed(struct r8152 *tp)
{
	return ocp_read_byte(tp, MCU_TYPE_PLA, PLA_PHYSTATUS);
}