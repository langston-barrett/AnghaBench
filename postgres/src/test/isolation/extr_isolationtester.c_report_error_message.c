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
struct TYPE_3__ {char* errormsg; } ;
typedef  TYPE_1__ Step ;

/* Variables and functions */
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  stdout ; 

__attribute__((used)) static void
report_error_message(Step *step)
{
	if (step->errormsg)
	{
		fprintf(stdout, "%s\n", step->errormsg);
		free(step->errormsg);
		step->errormsg = NULL;
	}
}