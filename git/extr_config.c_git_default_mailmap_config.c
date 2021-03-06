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
 int git_config_pathname (int /*<<< orphan*/ *,char const*,char const*) ; 
 int git_config_string (int /*<<< orphan*/ *,char const*,char const*) ; 
 int /*<<< orphan*/  git_mailmap_blob ; 
 int /*<<< orphan*/  git_mailmap_file ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 

__attribute__((used)) static int git_default_mailmap_config(const char *var, const char *value)
{
	if (!strcmp(var, "mailmap.file"))
		return git_config_pathname(&git_mailmap_file, var, value);
	if (!strcmp(var, "mailmap.blob"))
		return git_config_string(&git_mailmap_blob, var, value);

	/* Add other config variables here and to Documentation/config.txt. */
	return 0;
}