#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {char const* dsmnt; } ;
typedef  TYPE_1__ differ_info_t ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  stream_bytes (int /*<<< orphan*/ *,char const*) ; 

__attribute__((used)) static void
print_cmn(FILE *fp, differ_info_t *di, const char *file)
{
	stream_bytes(fp, di->dsmnt);
	stream_bytes(fp, file);
}