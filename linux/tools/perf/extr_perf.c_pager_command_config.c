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
struct pager_config {int /*<<< orphan*/  val; int /*<<< orphan*/  cmd; } ;

/* Variables and functions */
 int /*<<< orphan*/  perf_config_bool (char const*,char const*) ; 
 int /*<<< orphan*/  strcmp (char const*,int /*<<< orphan*/ ) ; 
 scalar_t__ strstarts (char const*,char*) ; 

__attribute__((used)) static int pager_command_config(const char *var, const char *value, void *data)
{
	struct pager_config *c = data;
	if (strstarts(var, "pager.") && !strcmp(var + 6, c->cmd))
		c->val = perf_config_bool(var, value);
	return 0;
}