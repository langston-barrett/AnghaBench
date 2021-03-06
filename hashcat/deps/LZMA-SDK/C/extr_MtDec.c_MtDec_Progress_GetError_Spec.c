#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ UInt64 ;
struct TYPE_4__ {scalar_t__ res; int /*<<< orphan*/  cs; int /*<<< orphan*/  totalOutSize; int /*<<< orphan*/  totalInSize; scalar_t__ progress; } ;
struct TYPE_5__ {scalar_t__ interruptIndex; TYPE_1__ mtProgress; scalar_t__ needInterrupt; } ;
typedef  scalar_t__ SRes ;
typedef  TYPE_2__ CMtDec ;
typedef  int BoolInt ;

/* Variables and functions */
 int /*<<< orphan*/  CriticalSection_Enter (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  CriticalSection_Leave (int /*<<< orphan*/ *) ; 
 scalar_t__ ICompressProgress_Progress (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ SZ_ERROR_PROGRESS ; 
 scalar_t__ SZ_OK ; 

__attribute__((used)) static SRes MtDec_Progress_GetError_Spec(CMtDec *p, UInt64 inSize, UInt64 outSize, UInt64 interruptIndex, BoolInt *wasInterrupted)
{
  SRes res;
  CriticalSection_Enter(&p->mtProgress.cs);

  p->mtProgress.totalInSize += inSize;
  p->mtProgress.totalOutSize += outSize;
  if (p->mtProgress.res == SZ_OK && p->mtProgress.progress)
    if (ICompressProgress_Progress(p->mtProgress.progress, p->mtProgress.totalInSize, p->mtProgress.totalOutSize) != SZ_OK)
      p->mtProgress.res = SZ_ERROR_PROGRESS;

  *wasInterrupted = (p->needInterrupt && interruptIndex > p->interruptIndex);
  res = p->mtProgress.res;
  
  CriticalSection_Leave(&p->mtProgress.cs);

  return res;
}