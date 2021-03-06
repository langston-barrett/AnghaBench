#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/  (* PopAttrib ) (TYPE_2__*) ;} ;
struct TYPE_7__ {TYPE_1__ Exec; scalar_t__ ExecuteFlag; } ;
typedef  TYPE_2__ GLcontext ;

/* Variables and functions */
 int /*<<< orphan*/  OPCODE_POP_ATTRIB ; 
 int /*<<< orphan*/  alloc_instruction (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (TYPE_2__*) ; 

void gl_save_PopAttrib( GLcontext *ctx )
{
   (void) alloc_instruction( ctx, OPCODE_POP_ATTRIB, 0 );
   if (ctx->ExecuteFlag) {
      (*ctx->Exec.PopAttrib)( ctx );
   }
}