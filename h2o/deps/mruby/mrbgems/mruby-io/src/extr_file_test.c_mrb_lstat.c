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
struct stat {int dummy; } ;
typedef  int /*<<< orphan*/  mrb_value ;
typedef  int /*<<< orphan*/  mrb_state ;

/* Variables and functions */
 int mrb_stat0 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct stat*,int) ; 

__attribute__((used)) static int
mrb_lstat(mrb_state *mrb, mrb_value obj, struct stat *st)
{
  return mrb_stat0(mrb, obj, st, 1);
}