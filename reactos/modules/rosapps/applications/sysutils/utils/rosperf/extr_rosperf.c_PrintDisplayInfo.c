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
typedef  int /*<<< orphan*/ * HDC ;

/* Variables and functions */
 int /*<<< orphan*/  BITSPIXEL ; 
 int /*<<< orphan*/ * GetDC (int /*<<< orphan*/ *) ; 
 int GetDeviceCaps (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HORZRES ; 
 int /*<<< orphan*/  PLANES ; 
 int /*<<< orphan*/  ReleaseDC (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  VERTRES ; 
 int /*<<< orphan*/  wprintf (char*,int,int,int) ; 

__attribute__((used)) static void
PrintDisplayInfo(void)
{
  HDC Dc;

  Dc = GetDC(NULL);
  if (NULL == Dc)
    {
      return;
    }

  wprintf(L"Display settings %d * %d * %d\n", GetDeviceCaps(Dc, HORZRES),
          GetDeviceCaps(Dc, VERTRES), GetDeviceCaps(Dc, BITSPIXEL) * GetDeviceCaps(Dc, PLANES));

  ReleaseDC(NULL, Dc);
}