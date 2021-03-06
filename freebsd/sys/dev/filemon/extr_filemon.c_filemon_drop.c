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
struct filemon {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  filemon_release (struct filemon*) ; 
 int /*<<< orphan*/  sx_xunlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static __inline void
filemon_drop(struct filemon *filemon)
{

	sx_xunlock(&filemon->lock);
	filemon_release(filemon);
}