#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* png_structp ;
typedef  int /*<<< orphan*/  png_size_t ;
typedef  TYPE_2__* png_color_16p ;
typedef  int* png_bytep ;
typedef  int png_byte ;
struct TYPE_8__ {int gray; int red; int green; int blue; } ;
struct TYPE_7__ {int bit_depth; scalar_t__ num_palette; } ;

/* Variables and functions */
 int PNG_COLOR_TYPE_GRAY ; 
 int PNG_COLOR_TYPE_PALETTE ; 
 int PNG_COLOR_TYPE_RGB ; 
 int /*<<< orphan*/  PNG_tRNS ; 
 int /*<<< orphan*/  png_debug (int,char*) ; 
 int /*<<< orphan*/  png_save_uint_16 (int*,int) ; 
 int /*<<< orphan*/  png_tRNS ; 
 int /*<<< orphan*/  png_warning (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  png_write_chunk (TYPE_1__*,int /*<<< orphan*/ ,int*,int /*<<< orphan*/ ) ; 

void /* PRIVATE */
png_write_tRNS(png_structp png_ptr, png_bytep trans, png_color_16p tran,
   int num_trans, int color_type)
{
#ifdef PNG_USE_LOCAL_ARRAYS
   PNG_tRNS;
#endif
   png_byte buf[6];

   png_debug(1, "in png_write_tRNS\n");
   if (color_type == PNG_COLOR_TYPE_PALETTE)
   {
      if (num_trans <= 0 || num_trans > (int)png_ptr->num_palette)
      {
         png_warning(png_ptr,"Invalid number of transparent colors specified");
         return;
      }
      /* write the chunk out as it is */
      png_write_chunk(png_ptr, png_tRNS, trans, (png_size_t)num_trans);
   }
   else if (color_type == PNG_COLOR_TYPE_GRAY)
   {
      /* one 16 bit value */
      if(tran->gray >= (1 << png_ptr->bit_depth))
      {
         png_warning(png_ptr,
           "Ignoring attempt to write tRNS chunk out-of-range for bit_depth");
         return;
      }
      png_save_uint_16(buf, tran->gray);
      png_write_chunk(png_ptr, png_tRNS, buf, (png_size_t)2);
   }
   else if (color_type == PNG_COLOR_TYPE_RGB)
   {
      /* three 16 bit values */
      png_save_uint_16(buf, tran->red);
      png_save_uint_16(buf + 2, tran->green);
      png_save_uint_16(buf + 4, tran->blue);
      if(png_ptr->bit_depth == 8 && (buf[0] | buf[2] | buf[4]))
         {
            png_warning(png_ptr,
              "Ignoring attempt to write 16-bit tRNS chunk when bit_depth is 8");
            return;
         }
      png_write_chunk(png_ptr, png_tRNS, buf, (png_size_t)6);
   }
   else
   {
      png_warning(png_ptr, "Can't write tRNS with an alpha channel");
   }
}