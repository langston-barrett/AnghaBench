#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  size_t uint32_t ;
struct TYPE_5__ {TYPE_1__** nodes; } ;
typedef  TYPE_2__ binary_heap_t ;
struct TYPE_4__ {scalar_t__ distance; } ;

/* Variables and functions */

__attribute__((used)) static inline uint32_t heap_smaller(binary_heap_t * heap, uint32_t i,
				    uint32_t j)
{
	return (heap->nodes[i]->distance < heap->nodes[j]->distance) ? 1 : 0;
}