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
struct au0828_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  au0828_write (struct au0828_dev*,int,int) ; 

__attribute__((used)) static void au0828_start_transport(struct au0828_dev *dev)
{
	au0828_write(dev, 0x608, 0x90);
	au0828_write(dev, 0x609, 0x72);
	au0828_write(dev, 0x60a, 0x71);
	au0828_write(dev, 0x60b, 0x01);

}