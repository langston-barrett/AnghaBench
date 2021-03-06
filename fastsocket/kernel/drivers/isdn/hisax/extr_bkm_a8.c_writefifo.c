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
typedef  int /*<<< orphan*/  u_char ;

/* Variables and functions */
 int /*<<< orphan*/  wordout (unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void
writefifo(unsigned int ale, unsigned int adr, u_char off, u_char * data, int size)
{
	int i;
	wordout(ale, off);
	for (i = 0; i < size; i++)
		wordout(adr, data[i]);
}