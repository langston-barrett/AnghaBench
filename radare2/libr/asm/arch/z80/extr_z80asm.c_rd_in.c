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

/* Variables and functions */
 int indx (char const**,char const**,int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int rd_in(const char **p) {
#define A 8
	const char *list[] = {
		"b", "c", "d", "e", "h", "l", "f", "a", NULL
	};
	return indx (p, list, 1, NULL);
}