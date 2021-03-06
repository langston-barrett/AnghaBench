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
 int /*<<< orphan*/  ENC_MAGIC_LEN ; 
 int /*<<< orphan*/  memcmp (char*,void*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int check_magic(void *magic)
{
	if (!memcmp("start", magic, ENC_MAGIC_LEN))
		return 0;

	if (!memcmp("asar1", magic, ENC_MAGIC_LEN))
		return 0;

	return -1;
}