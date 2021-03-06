#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
struct TYPE_3__ {int* key; int pos; } ;
typedef  TYPE_1__ mt19937_state ;

/* Variables and functions */
 int RK_STATE_LEN ; 

__attribute__((used)) static void init_genrand(mt19937_state *state, uint32_t s) {
  int mti;
  uint32_t *mt = state->key;

  mt[0] = s & 0xffffffffUL;
  for (mti = 1; mti < RK_STATE_LEN; mti++) {
    /*
     * See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier.
     * In the previous versions, MSBs of the seed affect
     * only MSBs of the array mt[].
     * 2002/01/09 modified by Makoto Matsumoto
     */
    mt[mti] = (1812433253UL * (mt[mti - 1] ^ (mt[mti - 1] >> 30)) + mti);
    /* for > 32 bit machines */
    mt[mti] &= 0xffffffffUL;
  }
  state->pos = mti;
  return;
}