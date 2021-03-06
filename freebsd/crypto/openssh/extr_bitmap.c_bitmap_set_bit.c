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
typedef  size_t u_int ;
struct bitmap {size_t top; size_t* d; } ;
typedef  size_t BITMAP_WTYPE ;

/* Variables and functions */
 size_t BITMAP_BITS ; 
 size_t BITMAP_WMASK ; 
 int reserve (struct bitmap*,size_t) ; 

int
bitmap_set_bit(struct bitmap *b, u_int n)
{
	int r;
	size_t offset;

	if ((r = reserve(b, n)) != 0)
		return r;
	offset = n / BITMAP_BITS;
	if (offset > b->top)
		b->top = offset;
	b->d[offset] |= (BITMAP_WTYPE)1 << (n & BITMAP_WMASK);
	return 0;
}