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
struct atmel_aes_dev {int dummy; } ;

/* Variables and functions */
 int atmel_aes_complete (struct atmel_aes_dev*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int atmel_aes_transfer_complete(struct atmel_aes_dev *dd)
{
	return atmel_aes_complete(dd, 0);
}