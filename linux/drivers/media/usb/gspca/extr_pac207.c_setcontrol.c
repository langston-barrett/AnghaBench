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
typedef  int u16 ;
struct gspca_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  pac207_write_reg (struct gspca_dev*,int,int) ; 

__attribute__((used)) static void setcontrol(struct gspca_dev *gspca_dev, u16 reg, u16 val)
{
	pac207_write_reg(gspca_dev, reg, val);
	pac207_write_reg(gspca_dev, 0x13, 0x01);	/* Bit 0, auto clear */
	pac207_write_reg(gspca_dev, 0x1c, 0x01);	/* not documented */
}