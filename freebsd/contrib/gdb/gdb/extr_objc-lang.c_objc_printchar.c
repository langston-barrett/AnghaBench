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
struct ui_file {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  fputs_filtered (char*,struct ui_file*) ; 
 int /*<<< orphan*/  objc_emit_char (int,struct ui_file*,char) ; 

__attribute__((used)) static void
objc_printchar (int c, struct ui_file *stream)
{
  fputs_filtered ("'", stream);
  objc_emit_char (c, stream, '\'');
  fputs_filtered ("'", stream);
}