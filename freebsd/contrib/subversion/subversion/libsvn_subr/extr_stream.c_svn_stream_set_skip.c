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
struct TYPE_3__ {int /*<<< orphan*/  skip_fn; } ;
typedef  TYPE_1__ svn_stream_t ;
typedef  int /*<<< orphan*/  svn_stream_skip_fn_t ;

/* Variables and functions */

void
svn_stream_set_skip(svn_stream_t *stream, svn_stream_skip_fn_t skip_fn)
{
  stream->skip_fn = skip_fn;
}