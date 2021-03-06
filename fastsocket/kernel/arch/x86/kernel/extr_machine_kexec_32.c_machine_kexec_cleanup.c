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
struct kimage {int /*<<< orphan*/  control_code_page; } ;

/* Variables and functions */
 int /*<<< orphan*/  machine_kexec_free_page_tables (struct kimage*) ; 
 scalar_t__ nx_enabled ; 
 int /*<<< orphan*/  set_pages_nx (int /*<<< orphan*/ ,int) ; 

void machine_kexec_cleanup(struct kimage *image)
{
	if (nx_enabled)
		set_pages_nx(image->control_code_page, 1);
	machine_kexec_free_page_tables(image);
}