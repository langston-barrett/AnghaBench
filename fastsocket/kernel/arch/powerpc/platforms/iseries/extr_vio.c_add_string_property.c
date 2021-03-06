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
struct property {int dummy; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 struct property* new_property (char const*,scalar_t__,char const*) ; 
 int /*<<< orphan*/  prom_add_property (struct device_node*,struct property*) ; 
 scalar_t__ strlen (char const*) ; 

__attribute__((used)) static int add_string_property(struct device_node *np, const char *name,
		const char *value)
{
	struct property *nprop = new_property(name, strlen(value) + 1, value);

	if (!nprop)
		return 0;
	prom_add_property(np, nprop);
	return 1;
}