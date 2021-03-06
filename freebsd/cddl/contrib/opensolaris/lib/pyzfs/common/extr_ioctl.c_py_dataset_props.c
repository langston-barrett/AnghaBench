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
struct TYPE_4__ {int /*<<< orphan*/  zc_name; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_1__ zfs_cmd_t ;
typedef  int /*<<< orphan*/  PyObject ;

/* Variables and functions */
 int /*<<< orphan*/  PyArg_ParseTuple (int /*<<< orphan*/ *,char*,char**) ; 
 int /*<<< orphan*/  ZFS_IOC_OBJSET_STATS ; 
 int /*<<< orphan*/  _ (char*) ; 
 int /*<<< orphan*/  add_ds_props (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * ioctl_with_dstnv (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  seterr (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static PyObject *
py_dataset_props(PyObject *self, PyObject *args)
{
	zfs_cmd_t zc = { 0 };
	int snaps;
	char *name;
	PyObject *nvl;

	if (!PyArg_ParseTuple(args, "s", &name))
		return (NULL);

	(void) strlcpy(zc.zc_name, name, sizeof (zc.zc_name));

	nvl = ioctl_with_dstnv(ZFS_IOC_OBJSET_STATS, &zc);
	if (nvl) {
		add_ds_props(&zc, nvl);
	} else {
		seterr(_("cannot access dataset %s"), name);
	}
	return (nvl);
}