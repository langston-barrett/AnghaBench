#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  whiteShader; } ;
struct TYPE_4__ {TYPE_1__ uiDC; } ;

/* Variables and functions */
 int /*<<< orphan*/  UI_AdjustFrom640 (float*,float*,float*,float*) ; 
 int /*<<< orphan*/  trap_R_DrawStretchPic (float,float,float,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_2__ uiInfo ; 

void UI_DrawTopBottom(float x, float y, float w, float h) {
	UI_AdjustFrom640( &x, &y, &w, &h );
	trap_R_DrawStretchPic( x, y, w, 1, 0, 0, 0, 0, uiInfo.uiDC.whiteShader );
	trap_R_DrawStretchPic( x, y + h - 1, w, 1, 0, 0, 0, 0, uiInfo.uiDC.whiteShader );
}