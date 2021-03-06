#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/ * val; int /*<<< orphan*/ * keyword; } ;
typedef  TYPE_1__ PQconninfoOption ;
typedef  int /*<<< orphan*/  PGconn ;

/* Variables and functions */
 TYPE_1__* PQconninfo (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  PQconninfoFree (TYPE_1__*) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ *,char*) ; 

__attribute__((used)) static bool
has_hostaddr(PGconn *conn)
{
	bool		used = false;
	PQconninfoOption *ciopt = PQconninfo(conn);

	for (PQconninfoOption *p = ciopt; p->keyword != NULL; p++)
	{
		if (strcmp(p->keyword, "hostaddr") == 0 && p->val != NULL)
		{
			used = true;
			break;
		}
	}

	PQconninfoFree(ciopt);
	return used;
}