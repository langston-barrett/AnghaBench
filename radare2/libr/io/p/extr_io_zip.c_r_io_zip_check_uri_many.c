#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {size_t len; int /*<<< orphan*/ * name; } ;

/* Variables and functions */
 TYPE_1__* ZIP_ALL_URIS ; 
 scalar_t__ r_io_zip_has_uri_substr (char const*) ; 
 int /*<<< orphan*/  strncmp (char const*,int /*<<< orphan*/ *,size_t) ; 

__attribute__((used)) static int r_io_zip_check_uri_many(const char *file) {
	int i;
	if (r_io_zip_has_uri_substr (file)) {
		for (i = 0; ZIP_ALL_URIS[i].name != NULL; i++) {
			if (!strncmp (file, ZIP_ALL_URIS[i].name, ZIP_ALL_URIS[i].len) && file[ZIP_ALL_URIS[i].len]) {
				return true;
			}
		}
	}
	return false;
}