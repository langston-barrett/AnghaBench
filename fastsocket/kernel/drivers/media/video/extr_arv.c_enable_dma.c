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

/* Variables and functions */
 int /*<<< orphan*/  M32R_DMAEN_PORTL ; 
 int /*<<< orphan*/  ar_outl (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void enable_dma(void)
{
	ar_outl(0x8080, M32R_DMAEN_PORTL);	/* enable DMA0 */
}