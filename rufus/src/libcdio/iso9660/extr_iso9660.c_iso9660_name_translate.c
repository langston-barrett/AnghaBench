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

/* Variables and functions */
 int iso9660_name_translate_ext (char const*,char*,int /*<<< orphan*/ ) ; 

int
iso9660_name_translate(const char *psz_oldname, char *psz_newname)
{
  return iso9660_name_translate_ext(psz_oldname, psz_newname, 0);
}