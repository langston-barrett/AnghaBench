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
typedef  int uint32_t ;
typedef  enum adreno_stencil_op { ____Placeholder_adreno_stencil_op } adreno_stencil_op ;

/* Variables and functions */
 int A6XX_RB_STENCIL_CONTROL_ZFAIL__MASK ; 
 int A6XX_RB_STENCIL_CONTROL_ZFAIL__SHIFT ; 

__attribute__((used)) static inline uint32_t A6XX_RB_STENCIL_CONTROL_ZFAIL(enum adreno_stencil_op val)
{
	return ((val) << A6XX_RB_STENCIL_CONTROL_ZFAIL__SHIFT) & A6XX_RB_STENCIL_CONTROL_ZFAIL__MASK;
}