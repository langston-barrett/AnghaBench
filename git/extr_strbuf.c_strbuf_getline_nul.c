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
struct strbuf {int dummy; } ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int strbuf_getdelim (struct strbuf*,int /*<<< orphan*/ *,char) ; 

int strbuf_getline_nul(struct strbuf *sb, FILE *fp)
{
	return strbuf_getdelim(sb, fp, '\0');
}