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
struct TYPE_5__ {TYPE_1__* chunks; } ;
typedef  TYPE_2__ compiler_state_t ;
struct TYPE_4__ {int /*<<< orphan*/ * m; } ;

/* Variables and functions */
 int NCHUNKS ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
freechunks(compiler_state_t *cstate)
{
	int i;

	for (i = 0; i < NCHUNKS; ++i)
		if (cstate->chunks[i].m != NULL)
			free(cstate->chunks[i].m);
}