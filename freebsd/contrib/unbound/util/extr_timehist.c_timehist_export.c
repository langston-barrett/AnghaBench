#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct timehist {size_t num; TYPE_1__* buckets; } ;
struct TYPE_2__ {scalar_t__ count; } ;

/* Variables and functions */

void 
timehist_export(struct timehist* hist, long long* array, size_t sz)
{
	size_t i;
	if(!hist) return;
	if(sz > hist->num)
		sz = hist->num;
	for(i=0; i<sz; i++)
		array[i] = (long long)hist->buckets[i].count;
}