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
struct lavfi {int /*<<< orphan*/  graph; } ;

/* Variables and functions */
 int /*<<< orphan*/  MP_DBG (struct lavfi*,char*,...) ; 
 int /*<<< orphan*/  av_free (char*) ; 
 char* avfilter_graph_dump (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void dump_graph(struct lavfi *c)
{
#if LIBAVFILTER_VERSION_MICRO >= 100
    MP_DBG(c, "Filter graph:\n");
    char *s = avfilter_graph_dump(c->graph, NULL);
    if (s)
        MP_DBG(c, "%s\n", s);
    av_free(s);
#endif
}