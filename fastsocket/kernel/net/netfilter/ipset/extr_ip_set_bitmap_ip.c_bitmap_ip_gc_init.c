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
struct ip_set {struct bitmap_ip* data; } ;
struct TYPE_3__ {unsigned long data; scalar_t__ expires; int /*<<< orphan*/  function; } ;
struct bitmap_ip {TYPE_1__ gc; int /*<<< orphan*/  timeout; } ;

/* Variables and functions */
 int HZ ; 
 int IPSET_GC_PERIOD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  add_timer (TYPE_1__*) ; 
 int /*<<< orphan*/  bitmap_ip_gc ; 
 int /*<<< orphan*/  init_timer (TYPE_1__*) ; 
 scalar_t__ jiffies ; 

__attribute__((used)) static void
bitmap_ip_gc_init(struct ip_set *set)
{
	struct bitmap_ip *map = set->data;

	init_timer(&map->gc);
	map->gc.data = (unsigned long) set;
	map->gc.function = bitmap_ip_gc;
	map->gc.expires = jiffies + IPSET_GC_PERIOD(map->timeout) * HZ;
	add_timer(&map->gc);
}