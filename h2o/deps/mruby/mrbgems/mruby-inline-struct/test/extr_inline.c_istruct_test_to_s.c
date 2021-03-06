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
typedef  int /*<<< orphan*/  mrb_value ;
typedef  int /*<<< orphan*/  mrb_state ;

/* Variables and functions */
 scalar_t__ mrb_istruct_ptr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_str_new_cstr (int /*<<< orphan*/ *,char const*) ; 

__attribute__((used)) static mrb_value
istruct_test_to_s(mrb_state *mrb, mrb_value self)
{
  return mrb_str_new_cstr(mrb, (const char*)mrb_istruct_ptr(self));
}