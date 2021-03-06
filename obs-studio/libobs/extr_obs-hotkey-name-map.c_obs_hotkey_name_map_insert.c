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
struct TYPE_3__ {int /*<<< orphan*/  root; } ;
typedef  TYPE_1__ obs_hotkey_name_map_t ;

/* Variables and functions */
 int /*<<< orphan*/  insert (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  strlen (char const*) ; 

__attribute__((used)) static void obs_hotkey_name_map_insert(obs_hotkey_name_map_t *trie,
				       const char *key, int v)
{
	if (!trie || !key)
		return;

	insert(NULL, &trie->root, key, strlen(key), v);
}