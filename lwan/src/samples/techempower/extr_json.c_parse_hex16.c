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
typedef  int uint16_t ;

/* Variables and functions */

__attribute__((used)) static bool parse_hex16(const char **sp, uint16_t *out)
{
	const char *s = *sp;
	uint16_t ret = 0;
	uint16_t i;
	uint16_t tmp;

	for (i = 0; i < 4; i++) {
		char c = *s++;
		if (c >= '0' && c <= '9')
			tmp = (uint16_t)(c - '0');
		else if (c >= 'A' && c <= 'F')
			tmp = (uint16_t)(c - 'A' + 10);
		else if (c >= 'a' && c <= 'f')
			tmp = (uint16_t)(c - 'a' + 10);
		else
			return false;

		ret = (uint16_t)((ret << 4) + tmp);
	}
	
	if (out)
		*out = ret;
	*sp = s;
	return true;
}