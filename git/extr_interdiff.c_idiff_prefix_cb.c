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
typedef  void strbuf ;
struct diff_options {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static struct strbuf *idiff_prefix_cb(struct diff_options *opt, void *data)
{
	return data;
}