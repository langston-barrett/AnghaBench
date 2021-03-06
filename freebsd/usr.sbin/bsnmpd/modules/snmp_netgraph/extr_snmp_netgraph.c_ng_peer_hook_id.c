#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u_int ;
struct ng_mesg {scalar_t__ data; } ;
struct TYPE_4__ {size_t hooks; } ;
struct hooklist {TYPE_3__* link; TYPE_1__ nodeinfo; } ;
typedef  int /*<<< orphan*/  ng_ID_t ;
struct TYPE_5__ {int /*<<< orphan*/  type; int /*<<< orphan*/  id; } ;
struct TYPE_6__ {int /*<<< orphan*/  peerhook; TYPE_2__ nodeinfo; int /*<<< orphan*/  ourhook; } ;

/* Variables and functions */
 int /*<<< orphan*/  LOG_ERR ; 
 int /*<<< orphan*/  NGM_GENERIC_COOKIE ; 
 int /*<<< orphan*/  NGM_LISTHOOKS ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  free (struct ng_mesg*) ; 
 struct ng_mesg* ng_dialog_id (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  strcpy (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  syslog (int /*<<< orphan*/ ,char*) ; 

int
ng_peer_hook_id(ng_ID_t node, const char *hook, char *peerhook)
{
	struct ng_mesg *resp;
	struct hooklist *hooklist;
	u_int i;
	int ret;

	if ((resp = ng_dialog_id(node, NGM_GENERIC_COOKIE, NGM_LISTHOOKS,
	    NULL, 0)) == NULL) {
		syslog(LOG_ERR, "get hook list: %m");
		exit(1);
	}
	hooklist = (struct hooklist *)(void *)resp->data;

	for (i = 0; i < hooklist->nodeinfo.hooks; i++)
		if (strcmp(hooklist->link[i].ourhook, hook) == 0)
			break;

	if (i == hooklist->nodeinfo.hooks) {
		free(resp);
		return (-1);
	}

	node = hooklist->link[i].nodeinfo.id;

	ret = 0;
	if (strcmp(hooklist->link[i].nodeinfo.type, "tee") == 0) {
		if (strcmp(hooklist->link[i].peerhook, "left") == 0)
			ret = ng_peer_hook_id(node, "right", peerhook);
		else if (strcmp(hooklist->link[i].peerhook, "right") == 0)
			ret = ng_peer_hook_id(node, "left", peerhook);
		else
			strcpy(peerhook, hooklist->link[i].peerhook);

	} else
		strcpy(peerhook, hooklist->link[i].peerhook);

	free(resp);

	return (ret);
}