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
struct ifvxlancfg {int dummy; } ;
typedef  int /*<<< orphan*/  cfg ;

/* Variables and functions */
 int /*<<< orphan*/  VXLAN_CMD_GET_CONFIG ; 
 int /*<<< orphan*/  bzero (struct ifvxlancfg*,int) ; 
 int do_cmd (int,int /*<<< orphan*/ ,struct ifvxlancfg*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
vxlan_exists(int sock)
{
	struct ifvxlancfg cfg;

	bzero(&cfg, sizeof(cfg));

	return (do_cmd(sock, VXLAN_CMD_GET_CONFIG, &cfg, sizeof(cfg), 0) != -1);
}