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
typedef  int /*<<< orphan*/  vita2d_texture ;

/* Variables and functions */
 int /*<<< orphan*/  SCE_GXM_TEXTURE_FORMAT_A8B8G8R8 ; 
 int /*<<< orphan*/ * vita2d_create_empty_texture_format (unsigned int,unsigned int,int /*<<< orphan*/ ) ; 

vita2d_texture *vita2d_create_empty_texture(unsigned int w, unsigned int h)
{
	return vita2d_create_empty_texture_format(w, h, SCE_GXM_TEXTURE_FORMAT_A8B8G8R8);
}