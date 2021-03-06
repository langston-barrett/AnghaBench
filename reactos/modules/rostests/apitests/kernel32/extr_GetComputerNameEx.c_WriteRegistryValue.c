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
typedef  scalar_t__ PCHAR ;
typedef  scalar_t__ LSTATUS ;
typedef  int /*<<< orphan*/  LPBYTE ;
typedef  scalar_t__ INT ;
typedef  int /*<<< orphan*/  HKEY ;

/* Variables and functions */
 int /*<<< orphan*/  HKEY_LOCAL_MACHINE ; 
 int /*<<< orphan*/  KEY_WRITE ; 
 scalar_t__ NO_ERROR ; 
 int /*<<< orphan*/  REG_SZ ; 
 int /*<<< orphan*/  RegCloseKey (int /*<<< orphan*/ ) ; 
 scalar_t__ RegOpenKeyExA (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ RegSetValueExA (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ strlen (scalar_t__) ; 

__attribute__((used)) static
LSTATUS
WriteRegistryValue(PCHAR ValueName, PCHAR Value)
{
    INT ErrorCode;
    HKEY ParametersKey;

    /* Open the database path key */
    ErrorCode = RegOpenKeyExA(HKEY_LOCAL_MACHINE,
                              "System\\CurrentControlSet\\Services\\Tcpip\\Parameters",
                              0,
                              KEY_WRITE,
                              &ParametersKey);
    if (ErrorCode == NO_ERROR)
    {
        /* Read the actual path */
        ErrorCode = RegSetValueExA(ParametersKey,
                                   ValueName,
                                   0,
                                   REG_SZ,
                                   (LPBYTE)Value,
                                   strlen(Value) + 1);

        /* Close the key */
        RegCloseKey(ParametersKey);
    }
    return ErrorCode;
}