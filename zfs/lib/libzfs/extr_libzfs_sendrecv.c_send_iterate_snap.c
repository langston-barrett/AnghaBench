#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {scalar_t__ dds_guid; scalar_t__ dds_creation_txg; } ;
struct TYPE_8__ {int /*<<< orphan*/  zfs_name; TYPE_1__ zfs_dmustats; } ;
typedef  TYPE_2__ zfs_handle_t ;
typedef  scalar_t__ uint64_t ;
struct TYPE_9__ {scalar_t__ tosnap_txg; scalar_t__ parent_fromsnap_guid; int /*<<< orphan*/  snapholds; scalar_t__ holds; int /*<<< orphan*/  snapprops; int /*<<< orphan*/  backup; void* seento; void* seenfrom; int /*<<< orphan*/  recursive; int /*<<< orphan*/  parent_snaps; int /*<<< orphan*/ * tosnap; scalar_t__ verbose; int /*<<< orphan*/ * fromsnap; } ;
typedef  TYPE_3__ send_data_t ;
typedef  int /*<<< orphan*/  nvlist_t ;
typedef  int boolean_t ;

/* Variables and functions */
 void* B_TRUE ; 
 int /*<<< orphan*/  NV_UNIQUE_NAME ; 
 int /*<<< orphan*/  TEXT_DOMAIN ; 
 int /*<<< orphan*/  VERIFY (int) ; 
 char* dgettext (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/ * fnvlist_alloc () ; 
 int /*<<< orphan*/  fnvlist_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int lzc_get_holds (int /*<<< orphan*/ ,int /*<<< orphan*/ **) ; 
 scalar_t__ nvlist_add_nvlist (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 scalar_t__ nvlist_add_uint64 (int /*<<< orphan*/ ,char*,scalar_t__) ; 
 scalar_t__ nvlist_alloc (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvlist_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  send_iterate_prop (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stderr ; 
 scalar_t__ strcmp (int /*<<< orphan*/ *,char*) ; 
 char* strrchr (int /*<<< orphan*/ ,char) ; 
 int /*<<< orphan*/  zfs_close (TYPE_2__*) ; 

__attribute__((used)) static int
send_iterate_snap(zfs_handle_t *zhp, void *arg)
{
	send_data_t *sd = arg;
	uint64_t guid = zhp->zfs_dmustats.dds_guid;
	uint64_t txg = zhp->zfs_dmustats.dds_creation_txg;
	char *snapname;
	nvlist_t *nv;
	boolean_t isfromsnap, istosnap, istosnapwithnofrom;

	snapname = strrchr(zhp->zfs_name, '@')+1;
	isfromsnap = (sd->fromsnap != NULL &&
	    strcmp(sd->fromsnap, snapname) == 0);
	istosnap = (sd->tosnap != NULL && (strcmp(sd->tosnap, snapname) == 0));
	istosnapwithnofrom = (istosnap && sd->fromsnap == NULL);

	if (sd->tosnap_txg != 0 && txg > sd->tosnap_txg) {
		if (sd->verbose) {
			(void) fprintf(stderr, dgettext(TEXT_DOMAIN,
			    "skipping snapshot %s because it was created "
			    "after the destination snapshot (%s)\n"),
			    zhp->zfs_name, sd->tosnap);
		}
		zfs_close(zhp);
		return (0);
	}

	VERIFY(0 == nvlist_add_uint64(sd->parent_snaps, snapname, guid));
	/*
	 * NB: if there is no fromsnap here (it's a newly created fs in
	 * an incremental replication), we will substitute the tosnap.
	 */
	if (isfromsnap || (sd->parent_fromsnap_guid == 0 && istosnap)) {
		sd->parent_fromsnap_guid = guid;
	}

	if (!sd->recursive) {
		if (!sd->seenfrom && isfromsnap) {
			sd->seenfrom = B_TRUE;
			zfs_close(zhp);
			return (0);
		}

		if ((sd->seento || !sd->seenfrom) && !istosnapwithnofrom) {
			zfs_close(zhp);
			return (0);
		}

		if (istosnap)
			sd->seento = B_TRUE;
	}

	VERIFY(0 == nvlist_alloc(&nv, NV_UNIQUE_NAME, 0));
	send_iterate_prop(zhp, sd->backup, nv);
	VERIFY(0 == nvlist_add_nvlist(sd->snapprops, snapname, nv));
	nvlist_free(nv);
	if (sd->holds) {
		nvlist_t *holds = fnvlist_alloc();
		int err = lzc_get_holds(zhp->zfs_name, &holds);
		if (err == 0) {
			VERIFY(0 == nvlist_add_nvlist(sd->snapholds,
			    snapname, holds));
		}
		fnvlist_free(holds);
	}

	zfs_close(zhp);
	return (0);
}