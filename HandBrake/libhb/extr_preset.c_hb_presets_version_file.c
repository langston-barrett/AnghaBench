#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  hb_value_t ;

/* Variables and functions */
 int /*<<< orphan*/ * hb_plist_parse_file (char const*) ; 
 int hb_presets_version (int /*<<< orphan*/ *,int*,int*,int*) ; 
 int /*<<< orphan*/  hb_value_free (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/ * hb_value_read_json (char const*) ; 

int hb_presets_version_file(const char *filename,
                            int *major, int *minor, int *micro)
{
    int result;

    hb_value_t *preset = hb_value_read_json(filename);
    if (preset == NULL)
        preset = hb_plist_parse_file(filename);
    if (preset == NULL)
        return -1;

    result = hb_presets_version(preset, major, minor, micro);
    hb_value_free(&preset);

    return result;
}