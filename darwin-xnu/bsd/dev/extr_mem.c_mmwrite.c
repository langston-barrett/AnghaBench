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
struct uio {int dummy; } ;
typedef  int /*<<< orphan*/  dev_t ;

/* Variables and functions */
 int /*<<< orphan*/  UIO_WRITE ; 
 int mmrw (int /*<<< orphan*/ ,struct uio*,int /*<<< orphan*/ ) ; 

int
mmwrite(dev_t dev, struct uio *uio)
{
	return (mmrw(dev, uio, UIO_WRITE));
}