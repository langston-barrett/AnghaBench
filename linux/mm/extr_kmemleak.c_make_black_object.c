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
 int /*<<< orphan*/  KMEMLEAK_BLACK ; 
 int /*<<< orphan*/  paint_ptr (unsigned long,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void make_black_object(unsigned long ptr)
{
	paint_ptr(ptr, KMEMLEAK_BLACK);
}