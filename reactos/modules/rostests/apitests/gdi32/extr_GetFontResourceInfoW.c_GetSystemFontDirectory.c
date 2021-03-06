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

/* Variables and functions */
 int /*<<< orphan*/  GetWindowsDirectoryW (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAX_PATH ; 
 int /*<<< orphan*/  lstrcatW (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static void
GetSystemFontDirectory(LPWSTR pszDir)
{
    GetWindowsDirectoryW(pszDir, MAX_PATH);
    lstrcatW(pszDir, L"\\Fonts");
}