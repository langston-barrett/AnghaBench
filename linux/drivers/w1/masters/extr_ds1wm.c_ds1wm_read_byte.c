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
struct ds1wm_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ds1wm_read (struct ds1wm_data*,int) ; 

__attribute__((used)) static u8 ds1wm_read_byte(void *data)
{
	struct ds1wm_data *ds1wm_data = data;

	return ds1wm_read(ds1wm_data, 0xff);
}