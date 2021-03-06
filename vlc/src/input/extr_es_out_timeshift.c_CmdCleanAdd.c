#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  p_fmt; } ;
struct TYPE_6__ {TYPE_1__ add; } ;
struct TYPE_7__ {TYPE_2__ u; } ;
typedef  TYPE_3__ ts_cmd_t ;

/* Variables and functions */
 int /*<<< orphan*/  es_format_Clean (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void CmdCleanAdd( ts_cmd_t *p_cmd )
{
    es_format_Clean( p_cmd->u.add.p_fmt );
    free( p_cmd->u.add.p_fmt );
}