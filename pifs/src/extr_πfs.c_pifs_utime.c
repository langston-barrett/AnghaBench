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
struct utimbuf {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  FULL_PATH (char const*) ; 
 int errno ; 
 int /*<<< orphan*/  full_path ; 
 int utime (int /*<<< orphan*/ ,struct utimbuf*) ; 

__attribute__((used)) static int pifs_utime(const char *path, struct utimbuf *times)
{
  FULL_PATH(path);
  int ret = utime(full_path, times);
  return ret == -1 ? -errno : ret;
}