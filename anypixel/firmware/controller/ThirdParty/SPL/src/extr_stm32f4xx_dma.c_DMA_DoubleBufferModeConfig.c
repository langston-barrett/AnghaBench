#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint32_t ;
struct TYPE_4__ {scalar_t__ CR; scalar_t__ M1AR; } ;
typedef  TYPE_1__ DMA_Stream_TypeDef ;

/* Variables and functions */
 scalar_t__ DMA_Memory_0 ; 
 scalar_t__ DMA_SxCR_CT ; 
 int /*<<< orphan*/  IS_DMA_ALL_PERIPH (TYPE_1__*) ; 
 int /*<<< orphan*/  IS_DMA_CURRENT_MEM (scalar_t__) ; 
 int /*<<< orphan*/  assert_param (int /*<<< orphan*/ ) ; 

void DMA_DoubleBufferModeConfig(DMA_Stream_TypeDef* DMAy_Streamx, uint32_t Memory1BaseAddr,
                                uint32_t DMA_CurrentMemory)
{  
  /* Check the parameters */
  assert_param(IS_DMA_ALL_PERIPH(DMAy_Streamx));
  assert_param(IS_DMA_CURRENT_MEM(DMA_CurrentMemory));

  if (DMA_CurrentMemory != DMA_Memory_0)
  {
    /* Set Memory 1 as current memory address */
    DMAy_Streamx->CR |= (uint32_t)(DMA_SxCR_CT);    
  }
  else
  {
    /* Set Memory 0 as current memory address */
    DMAy_Streamx->CR &= ~(uint32_t)(DMA_SxCR_CT);    
  }

  /* Write to DMAy Streamx M1AR */
  DMAy_Streamx->M1AR = Memory1BaseAddr;
}