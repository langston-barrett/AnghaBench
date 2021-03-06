#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {TYPE_2__* priv_data; } ;
typedef  TYPE_1__ URLContext ;
struct TYPE_7__ {int /*<<< orphan*/  seg_hd; } ;
typedef  TYPE_2__ HLSContext ;

/* Variables and functions */
 int /*<<< orphan*/  ffurl_close (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_segment_list (TYPE_2__*) ; 
 int /*<<< orphan*/  free_variant_list (TYPE_2__*) ; 

__attribute__((used)) static int hls_close(URLContext *h)
{
    HLSContext *s = h->priv_data;

    free_segment_list(s);
    free_variant_list(s);
    ffurl_close(s->seg_hd);
    return 0;
}