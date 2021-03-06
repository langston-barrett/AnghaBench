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
typedef  int /*<<< orphan*/  uint32_t ;
struct pcg_state_32 {int /*<<< orphan*/  state; } ;

/* Variables and functions */
 int /*<<< orphan*/  pcg_oneseq_32_step_r (struct pcg_state_32*) ; 
 int /*<<< orphan*/  pcg_output_rxs_m_xs_32_32 (int /*<<< orphan*/ ) ; 

inline uint32_t pcg_oneseq_32_rxs_m_xs_32_random_r(struct pcg_state_32 *rng) {
  uint32_t oldstate = rng->state;
  pcg_oneseq_32_step_r(rng);
  return pcg_output_rxs_m_xs_32_32(oldstate);
}