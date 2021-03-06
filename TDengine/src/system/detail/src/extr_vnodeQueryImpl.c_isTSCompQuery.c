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
struct TYPE_7__ {TYPE_2__* pSelectExpr; } ;
struct TYPE_5__ {scalar_t__ functionId; } ;
struct TYPE_6__ {TYPE_1__ pBase; } ;
typedef  TYPE_3__ SQuery ;

/* Variables and functions */
 scalar_t__ TSDB_FUNC_TS_COMP ; 

bool isTSCompQuery(SQuery *pQuery) { return pQuery->pSelectExpr[0].pBase.functionId == TSDB_FUNC_TS_COMP; }