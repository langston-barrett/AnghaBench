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
typedef  int /*<<< orphan*/  mbstate_t ;
struct TYPE_2__ {scalar_t__ ch; } ;
typedef  TYPE_1__ _GBKState ;

/* Variables and functions */

__attribute__((used)) static int
_GBK_mbsinit(const mbstate_t *ps)
{

	return (ps == NULL || ((const _GBKState *)ps)->ch == 0);
}