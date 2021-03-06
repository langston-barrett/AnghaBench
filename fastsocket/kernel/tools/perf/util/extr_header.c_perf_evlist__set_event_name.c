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
struct perf_evsel {scalar_t__ name; int /*<<< orphan*/  idx; } ;
struct perf_evlist {int dummy; } ;

/* Variables and functions */
 struct perf_evsel* perf_evlist__find_by_index (struct perf_evlist*,int /*<<< orphan*/ ) ; 
 scalar_t__ strdup (scalar_t__) ; 

__attribute__((used)) static void
perf_evlist__set_event_name(struct perf_evlist *evlist,
			    struct perf_evsel *event)
{
	struct perf_evsel *evsel;

	if (!event->name)
		return;

	evsel = perf_evlist__find_by_index(evlist, event->idx);
	if (!evsel)
		return;

	if (evsel->name)
		return;

	evsel->name = strdup(event->name);
}