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
typedef  int u8 ;
struct nct6775_data {int* fan_div; int has_fan; } ;

/* Variables and functions */
 int BIT (int) ; 
 int /*<<< orphan*/  NCT6775_REG_FANDIV1 ; 
 int /*<<< orphan*/  NCT6775_REG_FANDIV2 ; 
 int nct6775_read_value (struct nct6775_data*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void nct6775_update_fan_div(struct nct6775_data *data)
{
	u8 i;

	i = nct6775_read_value(data, NCT6775_REG_FANDIV1);
	data->fan_div[0] = i & 0x7;
	data->fan_div[1] = (i & 0x70) >> 4;
	i = nct6775_read_value(data, NCT6775_REG_FANDIV2);
	data->fan_div[2] = i & 0x7;
	if (data->has_fan & BIT(3))
		data->fan_div[3] = (i & 0x70) >> 4;
}