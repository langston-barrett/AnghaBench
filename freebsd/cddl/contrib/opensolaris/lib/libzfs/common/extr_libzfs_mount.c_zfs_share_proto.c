#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;
typedef  struct TYPE_12__   TYPE_11__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zprop_source_t ;
typedef  size_t zfs_share_proto_t ;
struct TYPE_13__ {int /*<<< orphan*/  zfs_name; TYPE_2__* zfs_hdl; } ;
typedef  TYPE_1__ zfs_handle_t ;
typedef  int /*<<< orphan*/  shareopts ;
typedef  int /*<<< orphan*/  mountpoint ;
struct TYPE_14__ {int /*<<< orphan*/  libzfs_sharehdl; } ;
typedef  TYPE_2__ libzfs_handle_t ;
struct TYPE_12__ {int /*<<< orphan*/  p_share_err; int /*<<< orphan*/  p_name; int /*<<< orphan*/  p_prop; } ;

/* Variables and functions */
 int /*<<< orphan*/  B_FALSE ; 
 int /*<<< orphan*/  EZFS_SHARENFSFAILED ; 
 size_t PROTO_END ; 
 size_t PROTO_NFS ; 
 int /*<<< orphan*/  SA_INIT_ONE_SHARE_FROM_HANDLE ; 
 int SA_OK ; 
 int /*<<< orphan*/  TEXT_DOMAIN ; 
 int /*<<< orphan*/  ZFS_EXPORTS_PATH ; 
 int ZFS_MAXPROPLEN ; 
 int /*<<< orphan*/  ZFS_PROP_ZONED ; 
 char* _sa_errorstr (int) ; 
 int _sa_zfs_process_share (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dgettext (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,size_t) ; 
 int fsshare (int /*<<< orphan*/ ,char*,char*) ; 
 TYPE_11__* proto_table ; 
 int /*<<< orphan*/ * share ; 
 int /*<<< orphan*/  stderr ; 
 scalar_t__ strcmp (char*,char*) ; 
 int /*<<< orphan*/  zfs_error_fmt (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  zfs_get_name (TYPE_1__*) ; 
 int zfs_init_libshare_arg (TYPE_2__*,int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  zfs_is_mountable (TYPE_1__*,char*,int,int /*<<< orphan*/ *) ; 
 scalar_t__ zfs_prop_get (TYPE_1__*,int /*<<< orphan*/ ,char*,int,int /*<<< orphan*/ *,char*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ zfs_prop_get_int (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int zfs_sa_enable_share (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * zfs_sa_find_share (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int
zfs_share_proto(zfs_handle_t *zhp, zfs_share_proto_t *proto)
{
	char mountpoint[ZFS_MAXPROPLEN];
	char shareopts[ZFS_MAXPROPLEN];
	char sourcestr[ZFS_MAXPROPLEN];
	libzfs_handle_t *hdl = zhp->zfs_hdl;
	zfs_share_proto_t *curr_proto;
	zprop_source_t sourcetype;
	int error, ret;

	if (!zfs_is_mountable(zhp, mountpoint, sizeof (mountpoint), NULL))
		return (0);

	for (curr_proto = proto; *curr_proto != PROTO_END; curr_proto++) {
		/*
		 * Return success if there are no share options.
		 */
		if (zfs_prop_get(zhp, proto_table[*curr_proto].p_prop,
		    shareopts, sizeof (shareopts), &sourcetype, sourcestr,
		    ZFS_MAXPROPLEN, B_FALSE) != 0 ||
		    strcmp(shareopts, "off") == 0)
			continue;
#ifdef illumos
		ret = zfs_init_libshare_arg(hdl, SA_INIT_ONE_SHARE_FROM_HANDLE,
		    zhp);
		if (ret != SA_OK) {
			(void) zfs_error_fmt(hdl, EZFS_SHARENFSFAILED,
			    dgettext(TEXT_DOMAIN, "cannot share '%s': %s"),
			    zfs_get_name(zhp), _sa_errorstr != NULL ?
			    _sa_errorstr(ret) : "");
			return (-1);
		}
#endif

		/*
		 * If the 'zoned' property is set, then zfs_is_mountable()
		 * will have already bailed out if we are in the global zone.
		 * But local zones cannot be NFS servers, so we ignore it for
		 * local zones as well.
		 */
		if (zfs_prop_get_int(zhp, ZFS_PROP_ZONED))
			continue;

#ifdef illumos
		share = zfs_sa_find_share(hdl->libzfs_sharehdl, mountpoint);
		if (share == NULL) {
			/*
			 * This may be a new file system that was just
			 * created so isn't in the internal cache
			 * (second time through). Rather than
			 * reloading the entire configuration, we can
			 * assume ZFS has done the checking and it is
			 * safe to add this to the internal
			 * configuration.
			 */
			if (_sa_zfs_process_share(hdl->libzfs_sharehdl,
			    NULL, NULL, mountpoint,
			    proto_table[*curr_proto].p_name, sourcetype,
			    shareopts, sourcestr, zhp->zfs_name) != SA_OK) {
				(void) zfs_error_fmt(hdl,
				    proto_table[*curr_proto].p_share_err,
				    dgettext(TEXT_DOMAIN, "cannot share '%s'"),
				    zfs_get_name(zhp));
				return (-1);
			}
			share = zfs_sa_find_share(hdl->libzfs_sharehdl,
			    mountpoint);
		}
		if (share != NULL) {
			int err;
			err = zfs_sa_enable_share(share,
			    proto_table[*curr_proto].p_name);
			if (err != SA_OK) {
				(void) zfs_error_fmt(hdl,
				    proto_table[*curr_proto].p_share_err,
				    dgettext(TEXT_DOMAIN, "cannot share '%s'"),
				    zfs_get_name(zhp));
				return (-1);
			}
		} else
#else
		if (*curr_proto != PROTO_NFS) {
			fprintf(stderr, "Unsupported share protocol: %d.\n",
			    *curr_proto);
			continue;
		}

		if (strcmp(shareopts, "on") == 0)
			error = fsshare(ZFS_EXPORTS_PATH, mountpoint, "");
		else
			error = fsshare(ZFS_EXPORTS_PATH, mountpoint, shareopts);
		if (error != 0)
#endif
		{
			(void) zfs_error_fmt(hdl,
			    proto_table[*curr_proto].p_share_err,
			    dgettext(TEXT_DOMAIN, "cannot share '%s'"),
			    zfs_get_name(zhp));
			return (-1);
		}

	}
	return (0);
}