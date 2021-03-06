#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  UCHAR ;
struct TYPE_5__ {int Current; int Size; scalar_t__ Buf; } ;
typedef  TYPE_1__ BUF ;

/* Variables and functions */
 int /*<<< orphan*/  WriteBuf (TYPE_1__*,int /*<<< orphan*/ *,int) ; 

void WriteBufBufWithOffset(BUF *b, BUF *bb)
{
	// Validate arguments
	if (b == NULL || bb == NULL)
	{
		return;
	}

	WriteBuf(b, ((UCHAR *)bb->Buf) + bb->Current, bb->Size - bb->Current);
}