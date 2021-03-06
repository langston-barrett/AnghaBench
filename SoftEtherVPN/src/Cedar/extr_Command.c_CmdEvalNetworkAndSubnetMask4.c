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
typedef  int /*<<< orphan*/  wchar_t ;
typedef  int /*<<< orphan*/  tmp ;
typedef  int /*<<< orphan*/  UINT ;
struct TYPE_5__ {int /*<<< orphan*/  (* Write ) (TYPE_1__*,int /*<<< orphan*/ ) ;} ;
typedef  TYPE_1__ CONSOLE ;

/* Variables and functions */
 int IsNetworkAddress32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int MAX_SIZE ; 
 int ParseIpAndSubnetMask4 (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  UniToStr (char*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  _UU (char*) ; 
 int /*<<< orphan*/  stub1 (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (TYPE_1__*,int /*<<< orphan*/ ) ; 

bool CmdEvalNetworkAndSubnetMask4(CONSOLE *c, wchar_t *str, void *param)
{
	char tmp[MAX_SIZE];
	UINT ip, mask;
	// Validate arguments
	if (c == NULL || str == NULL)
	{
		return false;
	}

	UniToStr(tmp, sizeof(tmp), str);

	if (ParseIpAndSubnetMask4(tmp, &ip, &mask) == false)
	{
		c->Write(c, _UU("CMD_PARSE_IP_SUBNET_ERROR_1"));
		return false;
	}

	if (IsNetworkAddress32(ip, mask) == false)
	{
		c->Write(c, _UU("CMD_PARSE_IP_SUBNET_ERROR_2"));
		return false;
	}

	return true;
}