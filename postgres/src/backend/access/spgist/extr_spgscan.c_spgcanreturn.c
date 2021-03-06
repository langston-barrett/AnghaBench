#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int canReturnData; } ;
struct TYPE_5__ {TYPE_1__ config; } ;
typedef  TYPE_2__ SpGistCache ;
typedef  int /*<<< orphan*/  Relation ;

/* Variables and functions */
 TYPE_2__* spgGetCache (int /*<<< orphan*/ ) ; 

bool
spgcanreturn(Relation index, int attno)
{
	SpGistCache *cache;

	/* We can do it if the opclass config function says so */
	cache = spgGetCache(index);

	return cache->config.canReturnData;
}