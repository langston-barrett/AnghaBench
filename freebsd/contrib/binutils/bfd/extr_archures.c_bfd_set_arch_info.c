#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  bfd_arch_info_type ;
struct TYPE_3__ {int /*<<< orphan*/  const* arch_info; } ;
typedef  TYPE_1__ bfd ;

/* Variables and functions */

void
bfd_set_arch_info (bfd *abfd, const bfd_arch_info_type *arg)
{
  abfd->arch_info = arg;
}