#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int end; int buffer; } ;
typedef  TYPE_1__ IjkFifoBuffer ;

/* Variables and functions */
 int ijk_av_fifo_size (TYPE_1__ const*) ; 

int ijk_av_fifo_space(const IjkFifoBuffer *f)
{
    return f->end - f->buffer - ijk_av_fifo_size(f);
}