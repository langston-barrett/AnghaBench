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
typedef  scalar_t__ u_int32_t ;

/* Variables and functions */
 int /*<<< orphan*/  pr_debug (char*,...) ; 

__attribute__((used)) static inline bool
id_match(u_int32_t min, u_int32_t max, u_int32_t id, bool invert)
{
	bool r;
	pr_debug("frag id_match:%c 0x%x <= 0x%x <= 0x%x", invert ? '!' : ' ',
		 min, id, max);
	r = (id >= min && id <= max) ^ invert;
	pr_debug(" result %s\n", r ? "PASS" : "FAILED");
	return r;
}