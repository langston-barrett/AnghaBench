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
typedef  int /*<<< orphan*/  HTHEME ;
typedef  int /*<<< orphan*/  HPEN ;

/* Variables and functions */
 int /*<<< orphan*/  CreatePen (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PS_SOLID ; 
 int /*<<< orphan*/  get_edge_color (int,int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static inline HPEN get_edge_pen (int edgeType, HTHEME theme, int part, int state)
{
    return CreatePen (PS_SOLID, 1, get_edge_color (edgeType, theme, part, state));
}