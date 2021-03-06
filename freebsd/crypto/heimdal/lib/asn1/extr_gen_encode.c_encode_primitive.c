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
 int /*<<< orphan*/  codefile ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char const*,char const*) ; 

__attribute__((used)) static void
encode_primitive (const char *typename, const char *name)
{
    fprintf (codefile,
	     "e = der_put_%s(p, len, %s, &l);\n"
	     "if (e) return e;\np -= l; len -= l; ret += l;\n\n",
	     typename,
	     name);
}