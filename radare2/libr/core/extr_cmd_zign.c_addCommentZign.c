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
struct TYPE_3__ {int /*<<< orphan*/  anal; } ;
typedef  TYPE_1__ RCore ;

/* Variables and functions */
 int r_sign_add_comment (int /*<<< orphan*/ ,char const*,char const*) ; 

__attribute__((used)) static bool addCommentZign(RCore *core, const char *name, const char *args0, int nargs) {
	const char *comment = args0;
	return r_sign_add_comment (core->anal, name, comment);
}