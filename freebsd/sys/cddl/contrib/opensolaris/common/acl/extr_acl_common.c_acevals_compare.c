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
struct TYPE_2__ {scalar_t__ key; } ;
typedef  TYPE_1__ acevals_t ;

/* Variables and functions */

__attribute__((used)) static int
acevals_compare(const void *va, const void *vb)
{
	const acevals_t *a = va, *b = vb;

	if (a->key == b->key)
		return (0);

	if (a->key > b->key)
		return (1);

	else
		return (-1);
}