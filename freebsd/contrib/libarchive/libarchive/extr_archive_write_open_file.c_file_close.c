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
struct write_FILE_data {int dummy; } ;
struct archive {int dummy; } ;

/* Variables and functions */
 int ARCHIVE_OK ; 
 int /*<<< orphan*/  free (struct write_FILE_data*) ; 

__attribute__((used)) static int
file_close(struct archive *a, void *client_data)
{
	struct write_FILE_data	*mine = client_data;

	(void)a; /* UNUSED */
	free(mine);
	return (ARCHIVE_OK);
}