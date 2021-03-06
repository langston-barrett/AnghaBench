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
struct thread {int dummy; } ;
struct fpreg32 {int /*<<< orphan*/ * r_regs; } ;
struct fpreg {int /*<<< orphan*/ * r_regs; } ;

/* Variables and functions */
 unsigned int NUMFPREGS ; 
 int set_fpregs (struct thread*,struct fpreg*) ; 

int
set_fpregs32(struct thread *td, struct fpreg32 *fpregs)
{
	struct fpreg fp;
	unsigned i;

	for (i = 0; i < NUMFPREGS; i++)
		fp.r_regs[i] = fpregs->r_regs[i];

	return (set_fpregs(td, &fp));
}