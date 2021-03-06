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
struct qedi_uio_dev {int /*<<< orphan*/  list; } ;

/* Variables and functions */
 int /*<<< orphan*/  __qedi_free_uio (struct qedi_uio_dev*) ; 
 int /*<<< orphan*/  list_del_init (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void qedi_free_uio(struct qedi_uio_dev *udev)
{
	if (!udev)
		return;

	list_del_init(&udev->list);
	__qedi_free_uio(udev);
}