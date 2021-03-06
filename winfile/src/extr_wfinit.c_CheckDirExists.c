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
typedef  int /*<<< orphan*/  LPWSTR ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CheckDrive (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DRIVEID (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  FUNC_SETDRIVE ; 
 int IsNetDrive (int /*<<< orphan*/ ) ; 
 scalar_t__ IsValidDisk (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SetCurrentDirectory (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  hwndFrame ; 

BOOL
CheckDirExists(
   LPWSTR szDir)
{
   BOOL bRet = FALSE;

   if (IsNetDrive(DRIVEID(szDir)) == 2) {

      CheckDrive(hwndFrame, DRIVEID(szDir), FUNC_SETDRIVE);
      return TRUE;
   }

   if (IsValidDisk(DRIVEID(szDir)))
      bRet = SetCurrentDirectory(szDir);

   return bRet;
}