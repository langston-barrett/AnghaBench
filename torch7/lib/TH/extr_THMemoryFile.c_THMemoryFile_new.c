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
typedef  int /*<<< orphan*/  THFile ;

/* Variables and functions */
 int /*<<< orphan*/ * THMemoryFile_newWithStorage (int /*<<< orphan*/ *,char const*) ; 

THFile *THMemoryFile_new(const char *mode)
{
  return THMemoryFile_newWithStorage(NULL, mode);
}