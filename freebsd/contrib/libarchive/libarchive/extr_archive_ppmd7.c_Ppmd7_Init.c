#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int Count; scalar_t__ Summ; int /*<<< orphan*/  Shift; } ;
struct TYPE_6__ {unsigned int MaxOrder; TYPE_1__ DummySee; } ;
typedef  TYPE_2__ CPpmd7 ;

/* Variables and functions */
 int /*<<< orphan*/  PPMD_PERIOD_BITS ; 
 int /*<<< orphan*/  RestartModel (TYPE_2__*) ; 

__attribute__((used)) static void Ppmd7_Init(CPpmd7 *p, unsigned maxOrder)
{
  p->MaxOrder = maxOrder;
  RestartModel(p);
  p->DummySee.Shift = PPMD_PERIOD_BITS;
  p->DummySee.Summ = 0; /* unused */
  p->DummySee.Count = 64; /* unused */
}