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
struct TYPE_3__ {int /*<<< orphan*/  stream; } ;
typedef  TYPE_1__ cli_out_data ;

/* Variables and functions */
 int /*<<< orphan*/  fputc_filtered (char,int /*<<< orphan*/ ) ; 
 TYPE_1__* ui_out_data (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uiout ; 

__attribute__((used)) static void
field_separator (void)
{
  cli_out_data *data = ui_out_data (uiout);
  fputc_filtered (' ', data->stream);
}