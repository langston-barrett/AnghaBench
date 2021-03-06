#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {scalar_t__ vi_mem_model; } ;

/* Variables and functions */
 TYPE_1__ VGLModeInfo ; 
 void** VGLSavePaletteBlue ; 
 void** VGLSavePaletteGreen ; 
 void** VGLSavePaletteRed ; 
 scalar_t__ V_INFO_MM_DIRECT ; 
 void* inb (int) ; 
 int /*<<< orphan*/  outb (int,int) ; 

void
VGLSavePalette()
{
  int i;

  if (VGLModeInfo.vi_mem_model == V_INFO_MM_DIRECT)
    return;
  outb(0x3C6, 0xFF);
  inb(0x3DA);
  outb(0x3C7, 0x00);
  for (i=0; i<256; i++) {
    VGLSavePaletteRed[i] = inb(0x3C9);
    inb(0x84);
    VGLSavePaletteGreen[i] = inb(0x3C9);
    inb(0x84);
    VGLSavePaletteBlue[i] = inb(0x3C9);
    inb(0x84);
  }
  inb(0x3DA);
  outb(0x3C0, 0x20);
}