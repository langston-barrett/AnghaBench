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
typedef  int /*<<< orphan*/  LPVOID ;
typedef  int /*<<< orphan*/ * LPDWORD ;
typedef  int /*<<< orphan*/  DWORD ;

/* Variables and functions */
 int /*<<< orphan*/ * NS_GetNSAddr (int /*<<< orphan*/ ) ; 

DWORD NS_GetNsMagic( LPVOID lpNSInfo )
{
  LPDWORD lpHdrInfo = NS_GetNSAddr( lpNSInfo );

  return lpHdrInfo[1];
}