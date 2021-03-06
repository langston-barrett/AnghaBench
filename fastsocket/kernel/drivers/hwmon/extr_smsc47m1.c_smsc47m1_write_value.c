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
typedef  scalar_t__ u8 ;
struct smsc47m1_data {scalar_t__ addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  outb_p (scalar_t__,scalar_t__) ; 

__attribute__((used)) static inline void smsc47m1_write_value(struct smsc47m1_data *data, u8 reg,
		u8 value)
{
	outb_p(value, data->addr + reg);
}