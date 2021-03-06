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
typedef  int /*<<< orphan*/  fd_set ;

/* Variables and functions */
 scalar_t__ FD_ISSET (int,int /*<<< orphan*/  const*) ; 
 int min (int,int) ; 

__attribute__((used)) static char *
fdbits(
	int		count,
	const fd_set*	set
	)
{
	static char buffer[256];
	char * buf = buffer;

	count = min(count,  255);

	while (count >= 0) {
		*buf++ = FD_ISSET(count, set) ? '#' : '-';
		count--;
	}
	*buf = '\0';

	return buffer;
}