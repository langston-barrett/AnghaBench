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
typedef  scalar_t__ u32 ;

/* Variables and functions */
 scalar_t__ MT_WTBL1_BASE ; 
 int MT_WTBL1_SIZE ; 

__attribute__((used)) static u32
mt7603_wtbl1_addr(int idx)
{
	return MT_WTBL1_BASE + idx * MT_WTBL1_SIZE;
}