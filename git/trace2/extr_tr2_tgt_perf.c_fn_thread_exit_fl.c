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
typedef  int /*<<< orphan*/  uint64_t ;
struct strbuf {int dummy; } ;

/* Variables and functions */
 struct strbuf STRBUF_INIT ; 
 int /*<<< orphan*/  perf_io_write_fl (char const*,int,char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct strbuf*) ; 
 int /*<<< orphan*/  strbuf_release (struct strbuf*) ; 

__attribute__((used)) static void fn_thread_exit_fl(const char *file, int line,
			      uint64_t us_elapsed_absolute,
			      uint64_t us_elapsed_thread)
{
	const char *event_name = "thread_exit";
	struct strbuf buf_payload = STRBUF_INIT;

	perf_io_write_fl(file, line, event_name, NULL, &us_elapsed_absolute,
			 &us_elapsed_thread, NULL, &buf_payload);
	strbuf_release(&buf_payload);
}