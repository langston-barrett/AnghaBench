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
typedef  int wchar_t ;

/* Variables and functions */
 int ENAMETOOLONG ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 

__attribute__((used)) static inline int write_unichar(wchar_t ch, char *output, int olen)
{
	if (olen < 5)
		return -ENAMETOOLONG;
	sprintf(output, ":%04x", ch);
	return 5;
}