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

/* Variables and functions */
 scalar_t__ at (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  check_range () ; 
 int /*<<< orphan*/  copy_past_newline (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  idx ; 
 int /*<<< orphan*/  init_string (int /*<<< orphan*/ ) ; 
 scalar_t__ iscommand (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pc ; 
 int /*<<< orphan*/  ptr ; 
 int /*<<< orphan*/  tos ; 

__attribute__((used)) static void
get_stuff_in_command ()
{
  tos++;
  check_range ();
  init_string (tos);

  while (at (ptr, idx))
    {
      if (iscommand (ptr, idx))
	break;
      idx = copy_past_newline (ptr, idx, tos);
    }
  pc++;
}