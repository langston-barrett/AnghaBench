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
struct TYPE_4__ {char const* value; int /*<<< orphan*/  name; struct TYPE_4__* next; } ;
typedef  TYPE_1__ pgParameterStatus ;
struct TYPE_5__ {TYPE_1__* pstatus; } ;
typedef  TYPE_2__ PGconn ;

/* Variables and functions */
 scalar_t__ strcmp (int /*<<< orphan*/ ,char const*) ; 

const char *
PQparameterStatus(const PGconn *conn, const char *paramName)
{
	const pgParameterStatus *pstatus;

	if (!conn || !paramName)
		return NULL;
	for (pstatus = conn->pstatus; pstatus != NULL; pstatus = pstatus->next)
	{
		if (strcmp(pstatus->name, paramName) == 0)
			return pstatus->value;
	}
	return NULL;
}