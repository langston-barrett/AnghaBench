#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {TYPE_1__* dopt; } ;
struct TYPE_9__ {int /*<<< orphan*/  dump; } ;
struct TYPE_8__ {scalar_t__ include_everything; } ;
typedef  TYPE_2__ DumpableObject ;
typedef  TYPE_3__ Archive ;

/* Variables and functions */
 int /*<<< orphan*/  DUMP_COMPONENT_ALL ; 
 int /*<<< orphan*/  DUMP_COMPONENT_NONE ; 
 scalar_t__ checkExtensionMembership (TYPE_2__*,TYPE_3__*) ; 

__attribute__((used)) static void
selectDumpablePublicationTable(DumpableObject *dobj, Archive *fout)
{
	if (checkExtensionMembership(dobj, fout))
		return;					/* extension membership overrides all else */

	dobj->dump = fout->dopt->include_everything ?
		DUMP_COMPONENT_ALL : DUMP_COMPONENT_NONE;
}